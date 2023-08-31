/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:40:56 by panger            #+#    #+#             */
/*   Updated: 2023/08/17 10:06:38 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	tot;

	tot = 1;
	if (power == 0 && nb == 0)
		return (1);
	else if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		while (power)
		{
			tot *= nb;
			power--;
		}
	}
	return (tot);
}
/* 
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_iterative_power(10,4));
} */
