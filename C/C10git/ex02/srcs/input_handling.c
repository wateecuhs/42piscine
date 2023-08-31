/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:06:27 by panger            #+#    #+#             */
/*   Updated: 2023/08/31 16:46:32 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	read_input_value(char *str)
{
	int	i;
	int	tot;

	i = 0;
	tot = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	else if (str[0] == '-')
	{
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		else
			tot = tot * 10 + (str[i] - 48);
		i++;
	}
	return (tot);
}

int	get_bytes2(char **argv, int *i, int argc)
{
	int	bytes;

	bytes = 0;
	*i = *i + 1;
	if (*i == argc)
	{
		ft_putstr_var("#: option requires an argument -- 'c'\n", argv[0]);
		ft_putstr("Try 'tail --help' for more information.\n");
		return (-1);
	}
	bytes = read_input_value(argv[*i]);
	if (bytes == -1)
	{
		ft_putstr(argv[0]);
		ft_putstr_var(": invalid number of bytes: '#'\n", argv[*i]);
		return (bytes);
	}
	return (bytes);
}

int	get_byte(char **argv, int *i, int argc)
{
	int	bytes;

	bytes = 0;
	if (argv[*i][2] != '\0')
	{
		bytes = read_input_value(&argv[*i][2]);
		if (bytes == -1)
		{
			ft_putstr(argv[0]);
			ft_putstr_var(": invalid number of bytes: '#'\n", &argv[*i][2]);
			return (bytes);
		}
	}
	else
	{
		bytes = get_bytes2(argv, i, argc);
		if (bytes == -1)
			return (bytes);
	}
	return (bytes);
}

int	read_input_bytes(int argc, char **argv)
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
			if (bytes == -1)
				return (bytes);
		}
		else
			files_taken += 1;
		i++;
	}
	return (bytes);
}
