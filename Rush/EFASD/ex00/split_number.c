/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:01:26 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 17:04:48 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	only_zeros(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	if_first_loop(int *i, int len)
{
	if (*i == 0)
	{
		if ((len - *i) % 3 == 0)
			*i = *i + 1;
		while ((len - *i) % 3 != 0)
			*i = *i + 1;
	}
	else
		*i = *i + 3;
}

void	sub_print_size(char *str, char *dict)
{
	char	*temp;

	temp = lookup_size(str, dict);
	if (temp == NULL)
		return ;
	ft_putstr(temp);
	free(temp);
}

void	sub_split_number(int *i, char *str, char *dict, int len)
{
	int		tempint;
	char	*temp;

	tempint = ft_atoi_first3(&str[*i], (ft_strlen(str) - *i) % 3);
	if (tempint != 0)
	{
		ft_putnbr(tempint, dict);
		if (len - *i > 3)
			write(1, " ", 1);
	}
	temp = find_size(&str[*i]);
	if (ft_strlen(temp) > 2 && tempint != 0)
	{
		sub_print_size(temp, dict);
	}
	free(temp);
	if_first_loop(i, ft_strlen(str));
}

void	split_number(char *str, char *dict)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (!check_error(str, dict))
	{
		return ;
	}
	if (only_zeros(str))
	{
		sub_putnbr(0, dict);
		write(1, "\n", 1);
		return ;
	}
	while ((len - i) > 0)
	{
		sub_split_number(&i, str, dict, len);
		if (only_zeros(&str[i]))
		{
			write(1, "\n", 1);
			return ;
		}
		else
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
