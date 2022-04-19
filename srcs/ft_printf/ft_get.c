/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:39:55 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/25 14:51:58 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_flag(t_printf **list)
{
	int	i;

	i = -1;
	while ((*list)->fs[++i])
	{
		if ((*list)->fs[i] == '-')
		{
			if ((*list)->dot == 0)
				(*list)->minus = 1;
			else if ((*list)->dot == 1)
				(*list)->minusprec = 1;
		}
		else if ((*list)->fs[i] == '*')
			(*list)->star = 1;
		else if ((*list)->fs[i] == '.')
			(*list)->dot = 1;
		else if ((*list)->fs[i] == '#')
			(*list)->hash = 1;
		else if ((*list)->fs[i] == ' ')
			(*list)->space = 1;
		else if ((*list)->fs[i] == '+')
			(*list)->plus = 1;
	}
}

void	ft_get_width(t_printf **list)
{
	while ((ft_strchr("-# +", (*list)->fs[(*list)->pos]))
		&& (*list)->fs[(*list)->pos] != '\0')
		(*list)->pos += 1;
	if ((*list)->fs[(*list)->pos] == '0')
	{
		(*list)->zero = 1;
		(*list)->pos += 1;
	}
	while ((*list)->fs[(*list)->pos] == '0' || (*list)->fs[(*list)->pos] == '-')
		(*list)->pos += 1;
	ft_get_length(list, 0);
	if ((*list)->fs[(*list)->pos] == '*')
	{
		(*list)->width = va_arg((*list)->args, int);
		(*list)->pos += 1;
	}
}

void	ft_get_tmp(t_printf **list, int tmp)
{
	while ((tmp / 10) > 0)
	{
		(*list)->pos += 1;
		tmp /= 10;
	}
}

void	ft_get_prec(t_printf **list)
{
	int		tmp;
	char	*tmpatoi;

	if ((*list)->fs[(*list)->pos] == '.')
	{
		(*list)->pos += 1;
		while ((*list)->fs[(*list)->pos] == '0')
			(*list)->pos += 1;
		if ((*list)->fs[(*list)->pos] >= '1'
			&& (*list)->fs[(*list)->pos] <= '9')
		{
			tmpatoi = &(*list)->fs[(*list)->pos];
			(*list)->prec = ft_atoi(tmpatoi);
			tmp = (*list)->prec;
			ft_get_tmp(list, tmp);
			(*list)->pos += 1;
		}
		if ((*list)->fs[(*list)->pos] == '*')
		{
			(*list)->prec = va_arg((*list)->args, int);
			(*list)->pos += 1;
		}
	}
}

void	ft_get_length(t_printf **list, int i)
{
	int		tmp;
	char	*tmpatoi;

	if (i == 0)
	{
		if ((*list)->fs[(*list)->pos] >= '1'
			&& (*list)->fs[(*list)->pos] <= '9')
		{
			tmpatoi = &(*list)->fs[(*list)->pos];
			(*list)->width = ft_atoi(tmpatoi);
			tmp = (*list)->width;
			ft_get_tmp(list, tmp);
			(*list)->pos += 1;
		}
	}
	if (i == 1)
	{
		if (ft_strchr("hlLjzt", (*list)->fs[(*list)->pos]))
		{
			(*list)->length = 1;
			(*list)->pos += 1;
			if (ft_strchr("hl", (*list)->fs[(*list)->pos]))
				(*list)->pos += 1;
		}
	}
}
