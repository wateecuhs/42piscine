/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:30:23 by brappo            #+#    #+#             */
/*   Updated: 2023/08/27 21:08:20 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*lookup_size(char *str, char *dict)
{
	char	*ret;
	int		i;

	i = 0;
	ret = line_by_line(dict, str);
	if (!ret)
	{
		return (NULL);
	}
	return (ret);
}

char	*find_size(char *str)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	while (i < ft_strlen(str))
	{
		i += 3;
	}
	ret = (char *)malloc(sizeof(char) * (i - 1));
	if (!ret)
		return (NULL);
	ret[0] = '1';
	j = 1;
	while (j < i - 2)
	{
		ret[j] = '0';
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
