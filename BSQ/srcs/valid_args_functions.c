/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:29:49 by lunagda           #+#    #+#             */
/*   Updated: 2023/08/30 15:33:40 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	first_line_is_valid(char *str)
{
	int	i;

	i = 0;
	while (i != (ft_strlen(str) - 3))
		i++;
	if (!((str[i] >= 32 && str[i] <= 126) 
			|| (str[i + 1] >= 32 && str[i + 1] <= 126)
			|| (str[i + 2] >= 32 && str[i + 2] <= 126)))
		return (-1);
	if (ft_compare(str[i], str[i + 1]) < 0 
		|| ft_compare(str[i], str[i + 2]) < 0 
		|| ft_compare(str[i + 1], str[i + 2]) < 0)
		return (-1);
	return (1);
}

int	check_for_chars(char **map)
{
	int		i;
	int		j;
	char	empty;
	char	obstacle;

	i = 0;
	while (i != (ft_strlen(map[0]) - 3))
		i++;
	empty = map[0][i++];
	obstacle = map[0][i++];
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((ft_compare(map[i][j], empty) > 0) 
				&& (ft_compare(map[i][j], obstacle) > 0))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_map_temp(char **map, char *temp)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	free(temp);
}
