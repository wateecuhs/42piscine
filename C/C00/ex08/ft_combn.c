/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:09:12 by panger            #+#    #+#             */
/*   Updated: 2023/08/17 15:54:26 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	tab_init(int n, int tab[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		tab[i] = (n - i - 1) * (n - i - 1 > 0);
		i++;
	}
}

void	write_tab(int tab[], int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		ft_putchar('0' + tab[i]);
		i--;
	}
}

void	increment(int tab[10])
{
	int	i;

	i = 0;
	while ((tab[i] + 1 > 9 - i) && (i < 9))
	{
		i ++;
	}
	tab[i]++;
	i--;
	while (i >= 0)
	{
		tab[i] = tab[i + 1] + 1;
		i --;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];

	if (n > 0 && n < 10)
	{
		tab_init(n, tab);
		while (tab[n] < 1)
		{
			write_tab(tab, n);
			increment(tab);
			if (tab[n] < 1)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}

/* int	main(void)
{
	ft_print_combn(10);
} */