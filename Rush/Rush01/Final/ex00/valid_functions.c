/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:45:18 by panger            #+#    #+#             */
/*   Updated: 2023/08/20 11:43:07 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_line_right(int tab[6][6], int y)
{
	int	i;
	int	count;
	int	highest;

	i = 4;
	count = 0;
	highest = 0;
	while (i > 0)
	{
		if (tab[i][y] > highest)
		{
			highest = tab[i][y];
			count++;
		}
		i--;
	}
	if (count != tab[5][y])
		return (0);
	return (1);
}

int	valid_col_down(int tab[6][6], int x)
{
	int	i;
	int	count;
	int	highest;

	i = 4;
	count = 0;
	highest = 0;
	while (i > 0)
	{
		if (tab[x][i] > highest)
		{
			highest = tab[x][i];
			count++;
		}
		i--;
	}
	if (count != tab[x][5])
		return (0);
	return (1);
}

int	valid_col(int tab[6][6], int x)
{
	int	i;
	int	count;
	int	highest;

	i = 1;
	count = 0;
	highest = 0;
	while (i < 5)
	{
		if (tab[x][i] > highest)
		{
			highest = tab[x][i];
			count++;
		}
		i++;
	}
	if (count != tab[x][0] || valid_col_down(tab, x) == 0)
		return (0);
	return (1);
}

int	valid_line(int tab[6][6], int y)
{
	int	i;
	int	count;
	int	highest;

	i = 1;
	count = 0;
	highest = 0;
	while (i < 5)
	{
		if (tab[i][y] > highest)
		{
			highest = tab[i][y];
			count++;
		}
		i++;
	}
	if (count != tab[0][y] || valid_line_right(tab, y) == 0)
		return (0);
	return (1);
}

#include <stdio.h>
int	is_valid(int tab[6][6], int x, int y)
{
	int	i;

	i = 1;
	if (!(tab[x][y] >= 1 && tab[x][y] <= 4))
		return (0);
	while (i < x)
	{
		if (tab[x][y] == tab[i][y])
		{
			printf("not valid for tab[%d][%d] = %d\n",x, y, tab[x][y]);
			return (0);
		}
		i++;
	}
	i = 1;
	while (i < y)
	{
		if (tab[x][y] == tab[x][i])
		{
			printf("not valid for tab[%d][%d] = %d\n",x, y, tab[x][y]);
			return (0);
		}
		i++;
	}
	return (1);
}
