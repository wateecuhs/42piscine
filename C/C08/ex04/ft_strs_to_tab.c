/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:39:37 by panger            #+#    #+#             */
/*   Updated: 2023/08/23 17:00:16 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ret;

	i = 0;
	ret = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (ret == NULL)
		return (NULL);
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].copy = ft_strdup(av[i]);
		ret[i].str = av[i];
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
