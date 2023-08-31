/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:12:01 by panger            #+#    #+#             */
/*   Updated: 2023/08/24 18:13:18 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i ++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	int		tot;
	char	*temp;

	tot = ft_strlen(dest) + ft_strlen(src);
	temp = (char *)malloc(sizeof(char) * (tot + 1));
	i = 0;
	while (dest[i])
	{
		temp[i] = dest[i];
		i ++;
	}
	temp[i] = '\0';
	j = 0;
	while (src[j])
	{
		temp[j + i] = src[j];
		j ++;
	}
	temp[j + i] = '\0';
	return (temp);
}

void	ft_putstr_var(char *str, char *var)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#')
		{
			write(1, &str[i], 1);
		}
		else
		{
			ft_putstr(var);
		}
		i++;
	}
}
