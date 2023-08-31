/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:19:29 by lunagda           #+#    #+#             */
/*   Updated: 2023/08/28 19:48:31 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	check_square(char **map, t_coords start, t_coords stop, t_coords map_len)
{
	unsigned int	i;
	unsigned int	j;

	i = start.x;
	while (i < map_len.x && i <= stop.x)
	{	
		j = start.y;
		while(j < map_len.y && j <= stop.y)
		{
			if (map[i][j] != '.')
			{
				//printf("%d %d is %c \n",i, j, map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_coords	biggest_square(char **map, t_coords cur, t_coords map_len, unsigned int biggest)
{
	unsigned int	i;
	unsigned int	j;
	t_coords		limit;
	t_coords		ret;

	i = cur.x;
	j = cur.y;
	limit.x = cur.x + biggest;
	limit.y = cur.y + biggest;
	while (limit.x < map_len.x && limit.y < map_len.y 
		&& check_square(map, cur, limit, map_len))
	{
		//printf("POSTION %d %d LIMIT %d %d MAPELN %d %d\n", i, j, limit.x, limit.y, map_len.x, map_len.y);
		i = limit.x;
		j = limit.y;
		limit.x++;
		limit.y++;
	}
	ret.x = i;
	ret.y = j;
	return (ret);
}

void	paint_square(char **map, t_coords start, int len, t_coords map_len)
{
	unsigned int	i;
	unsigned int	j;
	t_coords		stop;

	i = start.x;
	stop.x = start.x + len;
	stop.y = start.y + len;
	while (i <= stop.x)
	{
		j = start.y;
		while (j <= stop.y)
		{
			if (i < map_len.x && j < map_len.y)
				map[i][j] = 'x';
			j++;
		}
		i++;
	}
}
