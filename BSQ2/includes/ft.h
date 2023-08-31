/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:23:45 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 19:25:37 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_utils{
	char			empty;
	char			obstacle;
	char			to_place;
	unsigned int	len_x;
	unsigned int	len_y;
}	t_utils;

typedef struct s_coords{
	unsigned int	x;
	unsigned int	y;
}	t_coords;

int			check_square(char **map, t_coords start,
				t_coords stop, t_utils map_vars);
t_coords	biggest_square(char **map, t_coords cur, 
				t_utils map_vars, unsigned int biggest);
void		paint_square(char **map, t_coords start,
				int len, t_utils map_vars);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
char		*map_to_arr(char *filename);
int			solve_map(t_utils map_vars, char **map);
void		read_stdin(void);
char		*ft_modified_strdup(char *src, int start, int stop);
char		*ft_strdup(char *src);
int			ft_atoi(char *str);
int			ft_atoi_map_len(char *str);
int			first_line_is_valid(char *str);
int			check_for_chars(char **map);
int			valid_arg(char *filename);
char		**ft_split(char *str, char *charset);
int			ft_strlen_map(char **map);
char		*ft_strncpy(char *str, int n);
int			ft_strcmp(char *str1, char *str2);
int			count_file(char *str);
char		*get_str(char *str);
int			ft_strict_atoi(char *str);
int			ft_compare(char s1, char s2);
void		free_map_temp(char **map, char *temp);

#endif