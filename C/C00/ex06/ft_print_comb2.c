/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:49:31 by panger            #+#    #+#             */
/*   Updated: 2023/08/10 11:39:37 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int a, int b)
{
	ft_putchar(48 + (a / 10));
	ft_putchar(48 + (a % 10));
	ft_putchar(' ');
	ft_putchar(48 + (b / 10));
	ft_putchar(48 + (b % 10));
	if (a == 98 && b == 99)
		;
	else
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_number(a, b);
			b ++;
		}
		a ++;
	}
}
