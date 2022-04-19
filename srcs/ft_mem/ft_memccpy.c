/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:16:21 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/25 15:00:19 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*dst1++ = *src1++;
		if (*src1 == (unsigned char)c)
			return (dst1);
		i++;
	}
	return (NULL);
}
