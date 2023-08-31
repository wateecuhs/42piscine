/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:20:30 by lunagda           #+#    #+#             */
/*   Updated: 2023/08/30 19:38:45 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	sub_valid_arg(char *filename, char **temp, char ***map, int *len)
{
	*temp = get_str(filename);
	if (*temp == 0 || !(*temp))
		return (-1);
	*map = ft_split(*temp, "\n");
	*len = ft_strlen(*map[0]) - 3;
	free(*temp);
	*temp = ft_strncpy(*map[0], *len);
	*len = ft_strict_atoi(*temp);
	return (1);
}

int	check_map_for_length(char **map, char *temp)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[1]))
		{
			free_map_temp(map, temp);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	valid_arg(char *filename)
{
	char	*temp;
	int		len;
	char	**map;

	if (sub_valid_arg(filename, &temp, &map, &len) < 0 
		|| first_line_is_valid(map[0]) < 0 
		|| check_for_chars(map) < 0)
	{
		if (temp != 0)
			free_map_temp(map, temp);
		return (-1);
	}
	if (check_map_for_length(map, temp) < 0)
	{
		free_map_temp(map, temp);
		return (-1);
	}
	if (!(map[len] && !map[len + 1]))
	{
		free_map_temp(map, temp);
		return (-1);
	}
	free_map_temp(map, temp);
	return (1);
}
