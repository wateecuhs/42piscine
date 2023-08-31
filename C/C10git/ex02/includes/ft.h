/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:27:45 by panger            #+#    #+#             */
/*   Updated: 2023/08/25 12:29:21 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>

int		ft_strlen(char *str);
int		read_input_bytes(int argc, char **argv);
int		read_input_value(char *str);
void	ft_putstr(char *str);
void	read_stdin(void);
void	ft_putstr_var(char *str, char *var);

#endif