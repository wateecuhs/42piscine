/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:00:12 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 14:12:07 by lunagda          ###   ########.fr       */
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
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	tot;

	i = 0;
	sign = 1;
	tot = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tot = tot * 10 + (str[i] - '0');
		i ++;
	}
	return (sign * tot);
}

int	ft_atoi_map_len(char *str)
{
	int	i;
	int	sign;
	int	tot;
	int	j;

	i = 0;
	sign = 1;
	tot = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i -= 3;
	j = 0;
	while (str[j] >= '0' && str[j] <= '9' && j < i)
	{
		tot = tot * 10 + (str[j] - '0');
		j++;
	}
	return (sign * tot);
}
