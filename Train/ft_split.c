/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:21:00 by panger            #+#    #+#             */
/*   Updated: 2023/08/21 16:26:14 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *str, int start, int stop)
{
	char *ret;
	int	i;
	int len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	ret = (char *)malloc((stop - start + 1) * sizeof(char));
	while (start < stop && str[start])
	{
		ret[i] = str[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	next_charset(char *str, char *charset, int position)
{
	int	i;
	int	j;

	i = position;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset) == 0)	
		{
			i = next_charset(str, charset, i);
			count ++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		count;
	char	**tab;
	int		k;

	i = 0;
	count = count_words(str, charset);
	tab = (char **)malloc((count + 1)* sizeof(char *));
	if (tab == NULL)
		return (NULL);
	k = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset) == 0 || i == 0)
		{
			tab[k] = ft_strdup(str, i, next_charset(str, charset, i));
			k++;
			i = next_charset(str, charset, i);
		}
		i++;
	}
	tab[k] = 0;
	return (tab);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	char **tab;
	if (argc == 3)
	{
		tab = ft_split(argv[1], argv[2]);
		int i = 0;
		while (tab[i] != "\0")
		{
			printf("%s\n",tab[i]);
			i++;
		}
		printf("%s\n",tab[i]);
		free(tab);
	}
	return (0);
}