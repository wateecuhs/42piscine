/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_len_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:59:02 by lunagda           #+#    #+#             */
/*   Updated: 2023/08/29 10:46:15 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *str, int n)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[i] && i < n)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_compare(char s1, char s2)
{
	if (s1 == s2)
		return (-1);
	return (1);
}
