/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:57:05 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/20 13:50:18 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuhexa(unsigned int nbr)
{
	if (nbr > 15)
	{
		ft_putuhexa(nbr / 16);
		ft_putuhexa(nbr % 16);
	}
	else if (nbr < 10)
		ft_putchar(nbr + 48);
	else
		ft_putchar(nbr + 55);
}
