/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:14:59 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 11:55:27 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	sub_putnbr(int nb, char *dict)
{
	char	*temp;

	temp = lookup_word(nb, dict);
	if (temp == NULL)
		return ;
	ft_putstr(temp);
	free(temp);
}

void	ft_putnbr(unsigned long int nb, char *dict)
{
	if (nb <= 20)
	{
		sub_putnbr(nb, dict);
	}
	else if (nb <= 99)
	{
		sub_putnbr(nb - (nb % 10), dict);
		if (nb % 10 != 0)
		{
			write(1, " ", 1);
			ft_putnbr(nb % 10, dict);
		}
	}
	else if (nb <= 999)
	{
		ft_putnbr(nb / 100, dict);
		write(1, " ", 1);
		sub_putnbr(100, dict);
		if (nb % 100 != 0)
		{
			write(1, " ", 1);
			ft_putnbr(nb % 100, dict);
		}
	}
}
