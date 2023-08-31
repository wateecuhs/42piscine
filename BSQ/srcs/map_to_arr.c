/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:49:55 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 18:48:30 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_utils	fill_chars(t_utils map_vars, char *map_str)
{
	int		j;
	char	*first_line;

	j = 0;
	while (map_str[j] != '\n')
		j++;
	first_line = ft_modified_strdup(map_str, 0, j);
	j = 0;
	while (j != (ft_strlen(first_line) - 3))
		j++;
	map_vars.empty = first_line[j++];
	map_vars.obstacle = first_line[j++];
	map_vars.to_place = first_line[j];
	free(first_line);
	return (map_vars);
}

t_utils	fill_map(t_utils map_vars, char *map_str, char **map)
{
	int		i;
	int		line;

	map_vars = fill_chars(map_vars, map_str);
	i = 0;
	while (map_str[i] != '\n')
		i++;
	i += 1;
	line = 0;
	while (map_str[i])
	{
		map[line] = ft_strdup(&map_str[i]);
		line++;
		while (map_str[i] != '\n')
			i++;
		i++;
	}
	return (map_vars);
}

char	*map_to_arr(char *filename)
{
	char						*map_str;
	unsigned int				i;
	t_utils						map_vars;
	char						**map;

	map_str = get_str(filename);
	map_vars.len_x = ft_atoi_map_len(map_str);
	map = (char **)malloc(sizeof(char *) * (map_vars.len_x + 1));
	if (!map)
		return (NULL);
	map_vars = fill_map(map_vars, map_str, map);
	map_vars.len_y = ft_strlen(map[0]);
	free(map_str);
	solve_map(map_vars, map);
	i = 0;
	while (i < map_vars.len_x)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ((char *)0);
}
