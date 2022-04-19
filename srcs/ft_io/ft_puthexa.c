/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:56:14 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/20 11:59:22 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned int nbr)
{
	if (nbr > 15)
	{
		ft_puthexa(nbr / 16);
		ft_puthexa(nbr % 16);
	}
	else if (nbr < 10)
		ft_putchar(nbr + 48);
	else
		ft_putchar(nbr + 87);
}
