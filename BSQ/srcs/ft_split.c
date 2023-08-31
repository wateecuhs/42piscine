/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:23:37 by lunagda           #+#    #+#             */
/*   Updated: 2023/08/30 14:49:41 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_modified_strdup(char *src, int start, int stop)
{
	char	*trg;
	int		i;
	int		count;

	count = 0;
	while (src[count])
	{
		count++;
	}
	i = 0;
	trg = (char *)malloc((count + 1) * sizeof(char));
	while (src[start] && start < stop)
		trg[i++] = src[start++];
	trg[i] = '\0';
	return (trg);
}

int	is_seperator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((is_seperator(str[i + 1], charset) == 1) 
			&& (is_seperator(str[i], charset) == 0))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split_main_loop(char **tab, char *str, char *charset, int words)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (j < words)
	{
		while (str[i] && is_seperator(str[i], charset))
			i++;
		start = i;
		while (str[i] && !(is_seperator(str[i], charset)))
			i++;
		tab[j] = ft_modified_strdup(str, start, i);
		while (str[i] && is_seperator(str[i], charset))
			i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**tab;

	words = count_words(str, charset);
	tab = (char **)malloc((words + 1) * sizeof(char *));
	tab = ft_split_main_loop(tab, str, charset, words);
	return (tab);
}
