/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:51:25 by panger            #+#    #+#             */
/*   Updated: 2023/08/26 11:40:39 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long int	ft_recursive_power(int nb, int power)
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

/* #include <stdio.h>
int main(void)
{
	printf("%d",  ft_recursive_power(5, 4));
	return (0);
} */