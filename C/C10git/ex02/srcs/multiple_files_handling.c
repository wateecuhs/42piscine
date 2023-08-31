/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_files_handling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:27:33 by panger            #+#    #+#             */
/*   Updated: 2023/08/25 13:05:50 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	get_byte(char **argv, int *i, int argc);

int	read_input_files(int argc, char **argv)
{
	int	i;
	int	bytes;
	int	files_taken;

	i = 1;
	files_taken = 0;
	bytes = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'c')
		{
			bytes = get_byte(argv, &i, argc);
		}
		else
			files_taken += 1;
		i++;
	}
	return (files_taken);
}
