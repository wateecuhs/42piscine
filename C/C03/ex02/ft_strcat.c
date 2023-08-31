/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:29:16 by panger            #+#    #+#             */
/*   Updated: 2023/08/13 17:37:45 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* 
#include <stdio.h>
int	main(void)
{
	char dest[25] = "omg test";
	char src[8] = "working";

	ft_strcat(dest, src);
	printf("%s", dest);

} */