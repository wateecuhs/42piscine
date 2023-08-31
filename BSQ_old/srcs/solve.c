/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:46:31 by panger            #+#    #+#             */
/*   Updated: 2023/08/29 11:33:38 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	sub_solve_map(char **map, t_coords map_len, 
			t_coords *biggest_coords, unsigned int *biggest)
{
	unsigned int	i;
	unsigned int	j;
	t_coords		cur;

	i = 0;
	while (i < map_len.x - *biggest)
	{
		j = 0;
		while (j < map_len.y - *biggest)
		{
			cur.x = i;
			cur.y = j;
			//printf("checking for %d %d\n", i, j);
			if ((biggest_square(map, cur, map_len, *biggest).x - cur.x) > *biggest)
			{
				*biggest_coords = cur;
				*biggest = biggest_square(map, cur, map_len, *biggest).x - cur.x;
			}
			j++;
		}
		i++;
	}
}

int	solve_map(char **map, t_coords map_len)
{
	unsigned int	i;
	unsigned int	biggest;
	t_coords		biggest_coords;

	i = 0;
	biggest = 0;
	biggest_coords.x = 0;
	biggest_coords.y = 0;
	sub_solve_map(map, map_len, &biggest_coords, &biggest);
	paint_square(map, biggest_coords, biggest, map_len);
	printf("final is %d %d\n", biggest_coords.x, biggest_coords.y);
	while (i < map_len.x)
	{
		write(1, &map[i][0], map_len.y);
		ft_putstr("\n");
		i++;
	}
	return (biggest);
}
