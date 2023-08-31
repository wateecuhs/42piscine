/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:57:47 by panger            #+#    #+#             */
/*   Updated: 2023/08/20 16:26:02 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			if (s1[i] < s2[i])
				return (-1);
		}
		i++;
	}
	if (s1[i])
		return (1);
	if (s2[i])
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	b;

	i = 1;
	while (i < argc)
	{
		b = i + 1;
		while (b < argc)
		{
			if (compare(argv[i], argv[b]) == 1)
			{
				ft_swap(&argv[i], &argv[b]);
			}
			b ++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
