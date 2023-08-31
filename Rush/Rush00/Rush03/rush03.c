/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:23:39 by panger            #+#    #+#             */
/*   Updated: 2023/08/13 15:13:28 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	get_char(int x, int y, int i, int j)
{
	if ((j == 1 || j == y) && i == 1)
		return ('A');
	if ((j == 1 || j == y) && i == x)
		return ('C');
	if (((i != 1 && i != x) && (j == 1 || j == y)))
		return ('B');
	if (((j != 1 && j != y) && (i == 1 || i == x)))
		return ('B');
	else
		return (' ');
}

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	j = 1;
	if (x <= 0 || y <= 0)
	{
		return (0);
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
