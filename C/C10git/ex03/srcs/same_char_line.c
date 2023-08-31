/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_char_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:26:12 by panger            #+#    #+#             */
/*   Updated: 2023/08/31 15:05:11 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	same_char_line(unsigned char *str, unsigned char *str2, int stop)
{
	int	i;

	i = 0;
	if (stop > 16)
		stop = 16;
	while (i < stop)
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	combo_checker(unsigned char *str, unsigned int *len
	, unsigned int size, int *combo)
{
	if (*len > 16 && same_char_line(&str[*len]
			, &str[*len - 16], size - *len) == 1)
		*combo += 1;
	else
		*combo = 0;
	if (*combo > 0)
	{
		if (*combo == 1)
			write(1, "*\n", 2);
		*len += 16;
		return (0);
	}
	return (1);
}
