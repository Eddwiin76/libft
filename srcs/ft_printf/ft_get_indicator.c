/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_indicator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:50 by tpierre           #+#    #+#             */
/*   Updated: 2021/05/25 14:43:53 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_specifier2(t_printf **list)
{
	if ((*list)->fs[(*list)->pos] == 'f')
		(*list)->spe = 'f';
	if ((*list)->fs[(*list)->pos] == 'g')
		(*list)->spe = 'g';
	if ((*list)->fs[(*list)->pos] == 'e')
		(*list)->spe = 'e';
	if ((*list)->fs[(*list)->pos] == 'o')
		(*list)->spe = 'o';
	if ((*list)->fs[(*list)->pos] == 'E')
		(*list)->spe = 'E';
	if ((*list)->fs[(*list)->pos] == 'F')
		(*list)->spe = 'F';
	if ((*list)->fs[(*list)->pos] == 'G')
		(*list)->spe = 'G';
	if ((*list)->fs[(*list)->pos] == 'a')
		(*list)->spe = 'a';
	if ((*list)->fs[(*list)->pos] == 'A')
		(*list)->spe = 'A';
	if ((*list)->fs[(*list)->pos] == 'C')
		(*list)->spe = 'C';
	if ((*list)->fs[(*list)->pos] == 'S')
		(*list)->spe = 'S';
	if ((*list)->fs[(*list)->pos] == 'm')
		(*list)->spe = 'm';
	(*list)->pos += 1;
}

void	ft_get_specifier(t_printf **list)
{
	if ((*list)->fs[(*list)->pos] == 'c')
		(*list)->spe = 'c';
	if ((*list)->fs[(*list)->pos] == 's')
		(*list)->spe = 's';
	if ((*list)->fs[(*list)->pos] == 'p')
		(*list)->spe = 'p';
	if ((*list)->fs[(*list)->pos] == 'd')
		(*list)->spe = 'd';
	if ((*list)->fs[(*list)->pos] == 'i')
		(*list)->spe = 'i';
	if ((*list)->fs[(*list)->pos] == 'u')
		(*list)->spe = 'u';
	if ((*list)->fs[(*list)->pos] == 'x')
		(*list)->spe = 'x';
	if ((*list)->fs[(*list)->pos] == 'X')
		(*list)->spe = 'X';
	if ((*list)->fs[(*list)->pos] == '%')
		(*list)->spe = '%';
	if ((*list)->fs[(*list)->pos] == 'n')
		(*list)->spe = 'n';
	ft_get_specifier2(list);
}
