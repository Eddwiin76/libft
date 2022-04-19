/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:54:15 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/28 17:32:58 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_long(const char *str)
{
	int		u;
	long	nb;

	u = 1;
	nb = 0;
	while (*str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t'
		|| *str == '\v' || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			u = u * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
		nb = nb * 10 + (*str++ - 48);
	return (nb * u);
}
