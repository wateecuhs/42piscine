/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookupdict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:20:27 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 16:52:39 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*remove_leading_zeros(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	j = 0;
	if (str[i] == '\0')
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		while (str[i])
		{
			str[j] = str[i];
			i++;
			j++;
		}
		str[j] = '\0';
	}
	return (str);
}
	

char *atoa(char *input)
{
	int	i;
	int start;
	char *str;
	int	neg;

	i = 0;
	neg = 0;
	while (input[i] == ' ' || (input[i] >= 9 && input[i] <= 13))
		i++;
	if (input[i] == 43 || input[i] == 45)
	{
		if (input[i] == '-')
			neg = 1;
		i++;
	}
	start = i;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	if (start == i)
	{
		str = (char *)malloc(sizeof(char) * (2));
		str[0] = '0';
		str[1] ='\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (i - start + 1 + (neg == 1)));
	str[i - start] = '\0';
	i = 0;
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	while (input[start] >= '0' && input[start] <= '9')
	{
		str[i] = input[start];
		i++;
		start++;
	}
	str = remove_leading_zeros(str);
	return (str);
}

char	*line_by_line(char *dict, char* to_find)
{
	int	i;
	char	*temp;

	i = 0;
	while (dict[i])
	{
		if (i == 0 || dict[i - 1] == '\n')
		{
			temp = atoa(&dict[i]);
			if (strcmp(temp, to_find) == 0)
			{
				free(temp);
				return (ft_strdup(&dict[i + ft_strlen(to_find)]));
			}
			free(temp);
		}
		i++;
	}
	return (NULL);
}