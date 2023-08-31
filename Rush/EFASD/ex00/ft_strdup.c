/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:13:59 by brappo            #+#    #+#             */
/*   Updated: 2023/08/27 16:57:30 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	number_len(char *src)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (src[i] == ' ' || src[i] == ':')
			i++;
	while (src[i] && src[i] != '\n')
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char			*trg;
	unsigned int	count;
	int				i;
	int				j;

	count = number_len(src);
	i = 0;
	j = 0;
	trg = (char *)malloc((count + 1) * sizeof(char));
	while (src[j] == ' ' || src[j] == ':')
			j++;
	while (src[j] && src[j] != '\n')
	{
		trg[i] = src[j];
		i++;
		j++;
	}
	trg[i] = '\0';
	return (trg);
}
