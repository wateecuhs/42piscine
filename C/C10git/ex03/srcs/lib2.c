/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:12:03 by panger            #+#    #+#             */
/*   Updated: 2023/08/24 18:13:04 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i ++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putadr_hexa_c(unsigned long adr)
{
	char	*base;
	char	tab[8];
	int		i;

	base = "0123456789abcdef";
	i = 7;
	while (adr >= 16 && i > 0)
	{
		tab[i] = base[adr % 16];
		i--;
		adr = adr / 16;
	}
	tab[i--] = base[adr % 16];
	while (i >= 0)
	{
		tab[i] = '0';
		i--;
	}
	write(1, tab, 8);
}
