/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:57:31 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/20 13:51:03 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putunbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	else
		ft_putchar(nbr + 48);
}
