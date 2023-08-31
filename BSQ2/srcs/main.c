/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:23:00 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 19:37:56 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		read_stdin();
		if (valid_arg("pierre_luy_2709_1009") > 0)
			map_to_arr("pierre_luy_2709_1009");
		else
			ft_putstr("map error\n");
	}
	if (argc > 1)
	{
		while (i < argc)
		{
			if (valid_arg(argv[i]) > 0)
				map_to_arr(argv[i]);
			else
				ft_putstr("map error\n");
			ft_putstr("\n");
			i++;
		}
	}
}
