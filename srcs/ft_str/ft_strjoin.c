/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:09:12 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/25 13:08:06 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1ands2;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1ands2 = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (lens1ands2 + 1));
	if (!dst)
		return (NULL);
	ft_bzero(dst, lens1ands2 + 1);
	dst = ft_strcat(dst, s1);
	dst = ft_strcat(dst, s2);
	return (dst);
}
