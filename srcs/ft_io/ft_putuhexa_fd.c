/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhexa_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:57:05 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/20 11:57:09 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuhexa_fd(unsigned int nbr, int fd)
{
	if (nbr > 15)
	{
		ft_putuhexa_fd((nbr / 16), fd);
		ft_putuhexa_fd((nbr % 16), fd);
	}
	else if (nbr < 10)
		ft_putchar_fd((nbr + 48), fd);
	else
		ft_putchar_fd((nbr + 55), fd);
}
