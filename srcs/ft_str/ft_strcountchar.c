/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:39:17 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/25 13:06:34 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcountchar(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i++])
		if (str[i] == c)
			count++;
	return (count);
}
