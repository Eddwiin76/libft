/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:57:31 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/20 11:57:36 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int nbr, int fd)
{
	if (nbr > 9)
	{
		ft_putunbr_fd((nbr / 10), fd);
		ft_putchar_fd(((nbr % 10) + 48), fd);
	}
	else
		ft_putchar_fd((nbr + 48), fd);
}
