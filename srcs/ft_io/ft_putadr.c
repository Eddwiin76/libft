/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:54:28 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/20 11:59:05 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putadr(unsigned long nbr)
{
	if (nbr > 15)
	{
		ft_putadr(nbr / 16);
		ft_putadr(nbr % 16);
	}
	else if (nbr < 10)
		ft_putchar(nbr + 48);
	else
		ft_putchar(nbr + 87);
}
