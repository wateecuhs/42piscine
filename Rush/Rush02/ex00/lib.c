/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:38:31 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 18:08:33 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

unsigned long	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 2)
		return (nb * nb);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && (i < n))
	{
		if (s1[i] != s2[i])
		{
			if (!(s1[i] <= '9' && s1[i] >= '0'))
			{
				if (!(s2[i] <= '9' && s2[i] >= '0'))
					return (0);
				return (1);
			}
			if (s2[i] >= '0' && s2[i] <= '9')
				return (1);
			return (1);
		}
		i ++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i ++;
	}
	return (s1[i] - s2[i]);
}
