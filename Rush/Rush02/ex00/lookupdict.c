/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookupdict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:20:27 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 21:08:50 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*remove_leading_zeros(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '-')
		i++;
	j = i;
	while (str[i] && str[i] == '0')
		i++;
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

int	get_atoa_sign(int *i, int *start, char *input)
{
	int	neg;

	neg = 0;
	while (input[*i] == ' ' || (input[*i] >= 9 && input[*i] <= 13))
		*i = *i + 1;
	*start = *i;
	if (input[*i] == 43 || input[*i] == 45)
	{
		if (input[*i] == '-')
			neg = 1;
		else
			*start = *i + 1;
		*i = *i + 1;
	}
	while (input[*i] >= '0' && input[*i] <= '9')
		*i = *i + 1;
	return (neg);
}

char	*get_str_atoa(char *str, char *input, int start, int i)
{
	if (input[start] == '-')
	{
		str[i] = input[start];
		i++;
		start++;
	}
	while ((input[start] >= '0' && input[start] <= '9'))
	{
		str[i] = input[start];
		i++;
		start++;
	}
	str = remove_leading_zeros(str);
	return (str);
}

char	*atoa(char *input)
{
	int		i;
	int		start;
	char	*str;
	int		neg;

	i = 0;
	neg = get_atoa_sign(&i, &start, input);
	if (start == i)
	{
		str = (char *)malloc(sizeof(char) * (2));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (i - start + 1 + (neg == 1)));
	if (!str)
		return (NULL);
	str[i - start + (neg == i)] = '\0';
	i = 0;
	return (get_str_atoa(str, input, start, i));
}

char	*line_by_line(char *dict, char *to_find)
{
	int		i;
	char	*temp;

	i = 0;
	while (dict[i])
	{
		if ((i == 0 && dict[i] != '\n') 
			|| (dict[i - 1] == '\n' && dict[i] != '\n'))
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
