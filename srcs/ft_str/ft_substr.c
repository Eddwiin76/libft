/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:46:38 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/25 13:11:27 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	if (start > ft_strlen(s))
	{
		free(dst);
		return (ft_strdup(""));
	}
	i = 0;
	while (i < len && s[start])
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
