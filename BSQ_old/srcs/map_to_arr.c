/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:49:55 by panger            #+#    #+#             */
/*   Updated: 2023/08/28 19:12:55 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	count_file(char *str)
{
	int		fd;
	char	buf[100];
	int		char_read;
	int		count;

	char_read = -1;
	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (char_read != 0)
	{
		char_read = read(fd, buf, 99);
		if (char_read == -1)
			return (-1);
		count += char_read;
	}
	close(fd);
	return (count);
}

char	*get_str(char *str)
{
	char	*ret;
	int		fd;
	int		char_read;
	int		len;	

	len = count_file(str);
	if (len == -1)
		return (NULL);
	ret = (char *)malloc((len + 1) * sizeof(char));
	char_read = -1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	char_read = read(fd, ret, len);
	if (char_read == -1)
		return (NULL);
	ret[len] = '\0';
	close(fd);
	return (ret);
}

char	**fill_map(char **map, char *map_str, int i)
{
	int	line;

	line = 0;
	while (map_str[i])
	{
		map[line] = ft_strdup(&map_str[i]);
		line++;
		while (map_str[i] != '\n')
			i++;
		i++;
	}
	return (map);
}

char	**map_to_arr(void)
{
	char			*map_str;
	unsigned	int				i;
	struct t_coords	map_len;
	char			**map;

	map_str = get_str("map");
	i = 0;
	while (map_str[i] != '\n')
		i++;
	i += 1;
	map_len.x = ft_atoi(map_str);
	map = (char **)malloc(sizeof(char *) * (map_len.x + 1));
	if (!map)
		return (NULL);
	map = fill_map(map, map_str, i);
	map_len.y = ft_strlen(map[0]);
	free(map_str);
	solve_map(map, map_len);
	i = 0;
	while (i < map_len.x)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (map);
}
