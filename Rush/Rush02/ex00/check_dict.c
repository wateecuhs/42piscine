/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 08:18:18 by brappo            #+#    #+#             */
/*   Updated: 2023/08/27 21:06:49 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_line_empty(char *dict, int i)
{
	while (dict[i])
	{
		if (dict[i] == '\n')
			return (1);
		if (dict[i] != ' ' || !(dict[i] >= '\a' && dict[i] <= '\r'))
			break ;
		i++;
	}
	return (0);
}

int	check_line(char *str)
{
	int	i;
	int	j;

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
	j = 0;
	while (str[j] != ':')
		j++;
	j++;
	while (str[j] == ' ')
		j++;
	if (str[j] == '\n')
		return (0);
	return (1);
}

int	is_key_in_dict(int j, char *temp_i, char *dict)
{
	char	*temp_j;

	while (dict[j])
	{
		temp_j = atoa(dict + j);
		if (!ft_strcmp(temp_i, temp_j))
		{
			free(temp_i);
			free(temp_j);
			return (1);
		}
		free(temp_j);
		goto_nextline(&j, dict);
	}
	return (0);
}

int	check_dict(char *dict)
{
	int		i;
	int		j;
	int		len;
	char	*temp_i;

	if (dict == NULL)
		return (0);
	i = 0;
	while (dict[i])
	{
		if (!is_line_empty(dict, i))
		{
			if (!check_line(dict + i))
				return (0);
			temp_i = atoa(dict + i);
			len = number_len(dict + i);
			j = i;
			goto_nextline(&j, dict);
			if (is_key_in_dict(j, temp_i, dict))
				return (0);
			free(temp_i);
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
