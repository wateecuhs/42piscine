/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:41:05 by lunagda           #+#    #+#             */
/*   Updated: 2023/08/22 09:11:51 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src, int start, int stop)
{
	char			*trg;
	unsigned int	count;
	int				i;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	trg = (char *)malloc((count + 1) * sizeof(char));
	while (src[start] && start < stop)
	{
		trg[i] = src[start];
		i++;
		start++;
	}
	trg[i] = '\0';
	return (trg);
}

unsigned int	in_charset(char c, char *charset)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if (charset[j] == c)
		{
			return (1);
		}
		j++;
	}
	return (0);
}

unsigned int	next_charset(char *str, char *charset, int i)
{
	int	j;
	int	k;

	k = i;
	while (str[k])
	{
		j = 0;
		while (charset[j])
		{
			if (str[k] == charset[j])
				return (k);
			j++;
		}
		k++;
	}
	return (k);
}

unsigned int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((in_charset(str[i + 1], charset) == 1 || str[i + 1] == '\0')
			&& in_charset(str[i], charset) == 0)
		{
			count++;
		}
		i++;
	}
	if (count == 0)
		return (1);
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char			**tab;
	unsigned int	i;
	unsigned int	k;
	unsigned int	count;

	i = 0;
	k = 0;
	count = count_words(str, charset);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (str[i])
	{
		if (in_charset(str[i], charset) == 0)
		{
			tab[k++] = ft_strdup(str, i, next_charset(str, charset, i));
			i = next_charset(str, charset, i);
		}
		i++;
	}
	tab[k] = 0;
	return (tab);
}

/* int	main(int argc, char **argv)
{
	char	**tab;
	int		i;
	
	i = 0;
	(void)argc;
	tab = ft_split(argv[1], argv[2]);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%s \n", tab[i]);
} */