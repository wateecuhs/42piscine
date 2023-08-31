/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:17:13 by panger            #+#    #+#             */
/*   Updated: 2023/08/17 20:22:11 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_str(char *str)
{
	int i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a'  && str[i] <= 'z')	
		{
			if (str[i] >= 'a' + 13)
			{
				ft_putchar(str[i] - 13);
			}
			else
			{
				ft_putchar(str[i] + 13);
			}
		}
		else if (str[i] >= 'A'  && str[i] <= 'Z')
		{
			if (str[i] >= 'A' + 13)
			{
				ft_putchar(str[i] - 13);
			}
			else
			{
				ft_putchar(str[i] + 13);
			}
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		print_str(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}