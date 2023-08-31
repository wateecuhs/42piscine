/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:53:44 by panger            #+#    #+#             */
/*   Updated: 2023/08/18 13:04:50 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_s1(char *s1, int i)
{
	int	j;
	
	j = 0;
	while (j < i)
	{
		if (s1[i] == s1[j])
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int check_s2(char *s1, char *s2, int i)
{
	int	j;
	
	j = 0;
	while (s1[j])
	{
		if (s2[i] == s1[j])
		{
			return (0);
		}
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (s2[i] == s2[j])
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_union(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (check_s1(s1, i) == 1 || i == 0)
		{
			ft_putchar(s1[i]);
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (check_s2(s1, s2, i) == 1)
		{
			ft_putchar(s2[i]);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
}