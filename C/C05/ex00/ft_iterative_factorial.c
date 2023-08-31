/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:28:09 by panger            #+#    #+#             */
/*   Updated: 2023/08/16 17:02:42 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	tot;

	tot = 1;
	if (nb < 0)
		return (0);
	while (nb)
	{
		tot *= nb;
		nb--;
	}
	return (tot);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d",ft_iterative_factorial(11));
} */