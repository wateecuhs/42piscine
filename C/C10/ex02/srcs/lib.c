/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:05:54 by panger            #+#    #+#             */
/*   Updated: 2023/08/24 14:43:56 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
}

void	ft_putstr_var(char *str, char *var)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#')
		{
			write(1, &str[i], 1);
		}
		else
		{
			ft_putstr(var);
		}
		i++;
	}
}
