/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_files_handling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:27:33 by panger            #+#    #+#             */
/*   Updated: 2023/08/31 16:35:51 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	get_byte(char **argv, int *i, int argc);

int	read_input_value(char *str);

int	get_bytes2_buf(char **argv, int *i, int argc)
{
	int	bytes;

	bytes = 0;
	*i = *i + 1;
	if (*i == argc)
	{
		return (-1);
	}
	bytes = read_input_value(argv[*i]);
	if (bytes == -1)
	{
		return (bytes);
	}
	return (bytes);
}

int	get_byte_buf(char **argv, int *i, int argc)
{
	int	bytes;

	bytes = 0;
	if (argv[*i][2] != '\0')
	{
		bytes = read_input_value(&argv[*i][2]);
		if (bytes == -1)
		{
			return (bytes);
		}
	}
	else
	{
		bytes = get_bytes2_buf(argv, i, argc);
		if (bytes == -1)
			return (bytes);
	}
	return (bytes);
}

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
			bytes = get_byte_buf(argv, &i, argc);
		}
		else
			files_taken += 1;
		i++;
	}
	return (files_taken);
}
