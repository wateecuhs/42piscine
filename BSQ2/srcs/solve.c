/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:46:31 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 19:24:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	next_valid_in_line(char **map, t_utils map_vars, 
					t_coords *cur, unsigned int biggest)
{
	unsigned int	k;

	k = (*cur).y;
	while (map[(*cur).x][k] != map_vars.obstacle 
		&& map[(*cur).x][k] && (k - (*cur).y) <= biggest)
	{
		k++;
	}
	if (k - (*cur).y > biggest)
	{
		return (1);
	}
	else
	{
		(*cur).y = k + 1;
		return (-1);
	}
}

void	sub_solve_map(char **map, t_utils map_vars, 
	t_coords *biggest_coords, unsigned int *biggest)
{
	t_coords		cur;

	cur.x = 0;
	while (cur.x < map_vars.len_x - *biggest)
	{
		cur.y = 0;
		while (cur.y < map_vars.len_y - *biggest
			&& next_valid_in_line(map, map_vars, &cur, *biggest))
		{
			if ((biggest_square(map, cur, map_vars,
						*biggest).x - cur.x) > *biggest)
			{
				*biggest_coords = cur;
				*biggest = biggest_square(map, cur, map_vars, 
						*biggest).x - cur.x;
			}
			cur.y++;
		}
		cur.x++;
	}
}

int	solve_map(t_utils map_vars, char **map)
{
	unsigned int	i;
	unsigned int	biggest;
	t_coords		biggest_coords;

	i = 0;
	biggest = 0;
	biggest_coords.x = 0;
	biggest_coords.y = 0;
	sub_solve_map(map, map_vars, &biggest_coords, &biggest);
	paint_square(map, biggest_coords, biggest, map_vars);
	while (i < map_vars.len_x)
	{
		write(1, &map[i][0], map_vars.len_y);
		ft_putstr("\n");
		i++;
	}
	return (biggest);
}
