/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:23:45 by panger            #+#    #+#             */
/*   Updated: 2023/08/28 19:48:29 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

typedef struct chars{
	char	empty;
	char	obstacle;
	char	to_place;
}	t_chars;

typedef struct t_coords{
	unsigned int	x;
	unsigned int	y;
}	t_coords;

int			only_void(char *str, int stop);
int			check_square(char **map, t_coords start, 
				t_coords stop, t_coords map_len);
t_coords	biggest_square(char **map, t_coords cur, t_coords map_len, unsigned int biggest);
void		paint_square(char **map, t_coords start, int len, t_coords map_len);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
char		**map_to_arr(void);
int			solve_map(char **map, t_coords map_len);
void		read_stdin(void);
char		*ft_strdup(char *src);
int			ft_atoi(char *str);
int			ft_atoi_map_len(char *str, int stop);

#endif