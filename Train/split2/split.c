/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:20:14 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 14:38:47 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	word_count(char *str)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if(str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	next_space(char *str, int i)
{
	int k;

	k = i;
	while (str[k])
	{
		if (str[k] == ' ')
			return (k);
		k++;
	}
	return (k);
}

char *ft_strdup(char *src, int start, int stop)
{
	char *dest;
	int i;
	int count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	dest = (char *)malloc((count + 1) * sizeof(char));
	while (src[start] && start < stop)
	{
		dest[i] = src[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char **ft_split(char *str)
{
	int i;
	char **ret;
	int k;
	int len;

	i = 0;
	k = 0;
	len = word_count(str);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	printf("ici %d\n", len);
	while (str[i])
	{
		if (is_space(str[i]) == 0)
		{
			ret[k] = ft_strdup(str, i, next_space(str, i));
			i = next_space(str, i);
			k++;		
		}
		i++;
	}
	ret[k] = 0;
	return (ret);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		i;
	
	i = 0;
	(void)argc;
	tab = ft_split(argv[1]);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%s \n", tab[i]);
}