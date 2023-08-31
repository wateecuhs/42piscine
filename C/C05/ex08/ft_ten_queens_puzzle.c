/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:25:50 by panger            #+#    #+#             */
/*   Updated: 2023/08/18 13:57:26 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(tab[i] + 48);
		i++;
	}
	write (1, "\n", 1);
}

int	queen_is_valid(int *tab, int index)
{
	int	j;
	int	xdiff;
	int	ydiff;

	j = 0;
	while (j < index)
	{
		xdiff = index - j;
		ydiff = tab[index] - tab[j];
		if (tab[index] - tab[j] < 0)
			ydiff = -ydiff;
		if (xdiff == ydiff || tab[index] == tab[j])
			return (0);
		j++;
	}
	return (1);
}

int	solve_tab(int *tab, int col)
{
	int	count;

	count = 0;
	tab[col] = 0;
	if (col == 10)
	{
		print_tab(tab);
		return (1);
	}
	while (tab[col] < 10)
	{
		if (queen_is_valid(tab, col))
		{
			count += solve_tab(tab, col + 1);
		}
		tab[col] += 1;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[11];
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 10)
	{
		tab[i] = 0;
		i++;
	}
	count = solve_tab(tab, 0);
	return (count);
}

/* #include <stdio.h>
int	main(void)
{
	
	printf("\n%d\n",ft_ten_queens_puzzle());
	return (0);
}
 */
