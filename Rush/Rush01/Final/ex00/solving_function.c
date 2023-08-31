/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:35:18 by panger            #+#    #+#             */
/*   Updated: 2023/08/20 14:22:44 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		valid_line(int tab[6][6], int y);
int		valid_args(char *str);
int		is_valid(int tab[6][6], int x, int y);
void	print_tab(int tab[6][6]);
int		check_cols(int tab[6][6]);

void	assign_values(int tab[6][6], char *args)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (i < 31)
	{
		if (k < 5)
			tab[k][0] = args[i] - 48;
		else if (k < 9)
			tab[k - 4][5] = args[i] - 48;
		else if (k < 13)
			tab[0][k - 8] = args[i] - 48;
		else if (k < 17)
			tab[5][k - 12] = args[i] - 48;
		k++;
		i += 2;
	}
}

void	init_tab(int tab[6][6], char *args)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	assign_values(tab, args);
}

void	solve_tab(int tab[6][6], int x, int y, int *printed);

void	solve_tab_main_loop(int tab[6][6], int x, int y, int *printed)
{
	if (x != 5 && x != 0 && y != 5 && y != 0)
		tab[x][y] = 1;
	while (tab[x][y] < 5 && (x >= 1 && x <= 4 && y >= 1 && y <= 4))
	{
		if (is_valid(tab, x, y))
		{
			solve_tab(tab, x + 1, y, printed);
		}
		tab[x][y]++;
	}
}

void	solve_tab(int tab[6][6], int x, int y, int *printed)
{
	if (*printed == 1)
		return ;
	if (y == 5)
	{
		if (check_cols(tab) == 0)
			return ;
		else
		{
			print_tab(tab);
			*printed = 1;
		}
		return ;
	}
	if (x == 5)
	{
		if (valid_line(tab, y))
			solve_tab(tab, 1, y + 1, printed);
		else
			return ;
	}
	solve_tab_main_loop(tab, x, y, printed);
	return ;
}
