/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:07:58 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 18:07:27 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	find_tot_size(int size, char **strs, char *sep)
{
	int	tot;
	int	i;

	tot = 0;
	i = 0;
	while (i < size)
	{
		tot += ft_strlen(strs[i]);
		i ++;
	}
	tot += ft_strlen(sep) * (size - 1);
	return (tot);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	destlen;

	destlen = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[destlen + i] = src[i];
		i ++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	i = 0;
	if (size == 0)
	{
		return ((char *)malloc(sizeof(char)));
	}
	str = (char *)malloc((find_tot_size(size, strs, sep) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i != (size - 1))
		{
			str = ft_strcat(str, sep);
		}
		i++;
	}
	return (str);
}


/* #include <stdio.h>
int main(){
    char    *tab[] = {"test", "eqw", "bang"};
    char *r = ft_strjoin(3, tab, "1234");
    printf("%s",r);
	free(r);
} */