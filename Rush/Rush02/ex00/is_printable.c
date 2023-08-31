/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:17:14 by brappo            #+#    #+#             */
/*   Updated: 2023/08/27 21:10:06 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_in_dict(int nb, char *dict)
{
	char	*temp;

	temp = lookup_word(nb, dict);
	if (temp == NULL)
		return (0);
	free(temp);
	return (1);
}

int	is_size_in_dict(char *size, char *dict)
{
	char	*temp;

	temp = lookup_size(size, dict);
	if (temp == NULL)
		return (0);
	free(temp);
	return (1);
}

int	is_nbr_in_dict(unsigned long int nb, char *dict)
{
	if (nb <= 20)
	{
		if (!is_in_dict(nb, dict))
			return (0);
		return (1);
	}
	else if (nb <= 99)
	{
		if (!is_in_dict(nb % 10, dict))
			return (0);
		if (nb % 10 != 0)
			return (is_nbr_in_dict(nb % 10, dict));
	}
	else if (nb <= 999)
	{
		if (!is_nbr_in_dict(nb / 100, dict))
			return (0);
		if (!is_in_dict(100, dict))
			return (0);
		if (nb % 100 != 0)
			return (is_nbr_in_dict(nb % 100, dict));
	}
	return (1);
}

int	sub_is_printable(int *i, char *str, char *dict)
{
	int		tempint;
	char	*temp;

	tempint = ft_atoi_first3(&str[*i], (ft_strlen(str) - *i) % 3);
	if (tempint != 0)
	{
		if (!is_nbr_in_dict(tempint, dict))
			return (0);
	}
	temp = find_size(&str[*i]);
	if (!temp)
		return (0);
	if (ft_strlen(temp) > 2 && tempint != 0)
	{
		if (!is_size_in_dict(temp, dict))
		{
			free(temp);
			return (0);
		}
	}
	free(temp);
	if_first_loop(i, ft_strlen(str));
	return (1);
}

int	is_printable(char *str, char *dict)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (only_zeros(str))
	{
		if (!is_in_dict(0, dict))
			return (0);
		return (1);
	}
	while ((len - i) > 0)
	{
		if (!sub_is_printable(&i, str, dict))
			return (0);
		if (only_zeros(&str[i]))
		{
			if (!is_in_dict(0, dict))
				return (0);
			return (1);
		}
	}
	return (1);
}
