/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:35:24 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 19:23:43 by brappo           ###   ########.fr       */
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

char			*atoa(char *dict);
int				line_by_line_check(char *dict);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*lookup_word(unsigned long int nb, char *dict);
void			ft_putnbr(unsigned long int nb, char *dict);
void			ft_putstr(char *str);
unsigned long	ft_recursive_power(int nb, int power);
void			split_number(char *str, char *dict);
char			*get_str(char *str);
char			*ft_itoa(int nb);
char			*line_by_line(char *dict, char *tofind);
char			*find_size(char *str); 
void			read_stdin(char *dict);
int				ft_atoi_first3(char *str, int to_add);
char			*lookup_size(char *str, char *dict);
int				check_dict(char *dict);
int				number_len(char *src);
int				check_number(char *str);
void			if_first_loop(int *i, int len);
int				only_zeros(char *str);
int				is_printable(char *str, char *dict);
int				ft_strcmp(char *s1, char *s2);
int				check_error(char *str, char *dict);
void			sub_putnbr(int nb, char *dict);
void			goto_nextline(int *i, char *dict);

#endif
