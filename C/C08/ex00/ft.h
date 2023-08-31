/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:06:04 by panger            #+#    #+#             */
/*   Updated: 2023/08/22 11:57:03 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_putchar(char c);

void	ft_swap(int *a, int *b);

void	ft_putstr(char *str);

int		ft_strlen(char *str);

int		ft_strcmp(char *s1, char *s2);

#endif