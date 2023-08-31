/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeatalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:08:56 by panger            #+#    #+#             */
/*   Updated: 2023/08/17 20:14:42 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	int i;
	int	rep;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a'  && str[i] <= 'z')
		{
			rep = 0;
			while (rep < (str[i] - 'a'))
			{
				write(1, &str[i], 1);
				rep++;
			}
		}
		else if (str[i] >= 'A'  && str[i] <= 'Z')
		{
			rep = 0;
			while (rep < (str[i] - 'A'))
			{
				write(1, &str[i], 1);
				rep++;
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
		i++;
	}

}