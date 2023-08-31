/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:23:43 by panger            #+#    #+#             */
/*   Updated: 2023/08/13 15:44:09 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	get_char(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1) || ((i == x && x != 1) && (j == y && y != 1)))
		return ('o');
	if (((i == x && x != 1) && j == 1) || (i == 1 && (j == y && y != 1)))
		return ('o');
	if (((i != 1 && i != x) && (j == 1 || j == y)))
		return ('-');
	if (((j != 1 && j != y) && (i == 1 || i == x)))
		return ('|');
	else
		return (' ');
}

void	rush(int x, int y)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			ft_putchar(get_char(x, y, i, j));
			i ++;
		}
		ft_putchar('\n');
		j ++;
	}
}
