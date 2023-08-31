/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:02:41 by panger            #+#    #+#             */
/*   Updated: 2023/08/18 13:56:08 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;

	i = 5;
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb < 2 || nb % 3 == 0)
		return (0);
	while (i * i <= (unsigned int)nb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
	{
		nb++;
	}
	return (nb);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d", ft_find_next_prime(2147483646));
} */
