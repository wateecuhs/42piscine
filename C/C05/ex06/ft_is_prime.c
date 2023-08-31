/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:47:30 by panger            #+#    #+#             */
/*   Updated: 2023/08/18 13:55:54 by panger           ###   ########.fr       */
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

/* #include <stdio.h>
int	main(void)
{
	printf("%d", ft_is_prime(2147483647));
	return (0);
} */
