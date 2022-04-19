/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:17:19 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/25 18:31:19 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_exitprogram(char **data, char **bufforline)
{
	free(*data);
	free(*bufforline);
	return (-1);
}

int	ft_copy(char **data, char **line)
{
	char		*tmp;
	int			i;

	if (ft_strchr(*data, '\n'))
	{
		i = 0;
		while ((*data)[i] != '\n')
			i++;
		*line = ft_substr(*data, 0, i);
		tmp = ft_strdup(*data + i + 1);
		if (*line == NULL
			|| (tmp == NULL))
			return (ft_exitprogram(data, line));
		free(*data);
		*data = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(*data);
		if (*line == NULL)
			return (ft_exitprogram(data, NULL));
		ft_free_null(*data);
		return (0);
	}
}

int	ft_get_next_line_next(int fd, char **data, char *buff)
{
	int			len;
	char		*tmp;

	while (!ft_strchr(data[fd], '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len > 0)
		{
			buff[len] = '\0';
			tmp = ft_strjoin(data[fd], buff);
			if (tmp == NULL)
				return (ft_exitprogram(&data[fd], &buff));
			free(data[fd]);
			data[fd] = tmp;
		}
		else
			break ;
	}
	free(buff);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*data[9999];
	char		*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (data[fd] == NULL)
	{
		data[fd] = ft_strdup("");
		if (data[fd] == NULL)
			return (ft_exitprogram(NULL, &buff));
	}
	ft_get_next_line_next(fd, data, buff);
	return (ft_copy(&data[fd], line));
}
