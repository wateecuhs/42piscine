/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:53:19 by panger            #+#    #+#             */
/*   Updated: 2023/08/11 10:12:37 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i ++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = argc;
	while (i > 1)
	{
		ft_putstr(argv[i - 1]);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
