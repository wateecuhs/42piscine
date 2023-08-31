/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:19:29 by lunagda           #+#    #+#             */
/*   Updated: 2023/08/30 14:09:14 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_square(char **map, t_coords start, t_coords stop, t_utils map_vars)
{
	unsigned int	i;
	unsigned int	j;

	i = start.x;
	while (i < map_vars.len_x && i <= stop.x)
	{
		j = start.y;
		while (j < map_vars.len_y && j <= stop.y)
		{
			if (map[i][j] != map_vars.empty)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_coords	biggest_square(char **map, t_coords cur, 
				t_utils map_vars, unsigned int biggest)
{
	unsigned int	i;
	unsigned int	j;
	t_coords		limit;
	t_coords		ret;

	i = cur.x;
	j = cur.y;
	limit.x = cur.x + biggest;
	limit.y = cur.y + biggest;
	while (limit.x < map_vars.len_x && limit.y < map_vars.len_y 
		&& check_square(map, cur, limit, map_vars))
	{
		i = limit.x;
		j = limit.y;
		limit.x++;
		limit.y++;
	}
	ret.x = i;
	ret.y = j;
	return (ret);
}

void	paint_square(char **map, t_coords start, int len, t_utils map_vars)
{
	unsigned int	i;
	unsigned int	j;
	t_coords		stop;
	char			to_place;

	i = start.x;
	stop.x = start.x + len;
	stop.y = start.y + len;
	to_place = map_vars.to_place;
	while (i <= stop.x)
	{
		j = start.y;
		while (j <= stop.y)
		{
			if (i < map_vars.len_x && j < map_vars.len_y)
				map[i][j] = map_vars.to_place;
			j++;
		}
		i++;
	}
}
