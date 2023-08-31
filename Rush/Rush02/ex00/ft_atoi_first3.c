/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_first3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:18:10 by brappo            #+#    #+#             */
/*   Updated: 2023/08/26 17:46:32 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_sign(int *i, char *str)
{
	int	sign;

	sign = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i = *i + 1;
	}
	return (sign);
}

int	ft_atoi_first3(char *str, int to_add)
{
	int	i;
	int	sign;
	int	tot;
	int	b;

	i = 0;
	sign = 1;
	tot = 0;
	if (to_add == 0)
		to_add = 3;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = get_sign(&i, str);
	b = 0;
	while (str[i] >= '0' && str[i] <= '9' && b < to_add)
	{
		if (tot * 10 + (str[i] - '0') > 999)
			return (tot);
		tot = tot * 10 + (str[i] - '0');
		i ++;
		b++;
	}
	return (sign * tot);
}
