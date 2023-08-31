/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:07:20 by panger            #+#    #+#             */
/*   Updated: 2023/08/31 15:10:09 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	check_end_c(int count);
void	ft_putstr_hexa_c(unsigned char *str, unsigned int s, unsigned int len);
void	ft_putadr_hexa_c(unsigned long adr);
char	*ft_hexdump(void *adr, unsigned int size, int stdinval);
void	*ft_hexdump_c(void *adr, unsigned int size, int c, int stdinval);
void	ft_putadr_hexa(unsigned long adr);
int		ft_strlen(char *str);
int		read_file(char *str);
char	*ft_strcat(char *dest, char *src);
void	ft_putstr_var(char *str, char *var);
int		get_c_count(char **strs, int size);
void	read_input2(char *str, int c_mode);
void	ft_read_input(char **strs, int size);
char	*get_str(char *str);
void	read_stdin(int c_count);
int		same_char_line(unsigned char *str, unsigned char *str2, int stop);
int		combo_checker(unsigned char *str, unsigned int *len, 
			unsigned int size, int *combo);
int		ft_strcmp(char *s1, char *s2);

#endif