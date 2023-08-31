/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 08:18:18 by brappo            #+#    #+#             */
/*   Updated: 2023/08/27 17:05:09 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	goto_nextline(int *i, char *dict)
{
	while (dict[*i] && dict[*i] != '\n')
		*i = *i + 1;
	if (dict[*i] == '\n')
		*i = *i + 1;
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ':')
		return (0);
	while (str[i] && str[i] != '\n' && str[i] != ':')
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	if (str[i] == '\n')
		return (0);
	return (1);
}

int	check_dict(char *dict)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (dict[i])
	{
		if (!check_line(dict + i))
			return (0);
		while (dict[i] && dict[i] == ' ')
			i++;
		len = number_len(dict + i);
		j = i;
		goto_nextline(&j, dict);
		while (dict[j])
		{
			while (dict[j] && dict[j] == ' ')
				j++;
			if (!ft_strncmp(dict + i, dict + j, len + 1))
				return (0);
			goto_nextline(&j, dict);
		}
		goto_nextline(&i, dict);
	}
	return (1);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] == '.')
			return (0);
		i++;
	}
	return (1);
}

int	check_error(char *str, char *dict)
{
	if (!check_number(str))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!is_printable(str, dict))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (!check_dict(dict))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}
