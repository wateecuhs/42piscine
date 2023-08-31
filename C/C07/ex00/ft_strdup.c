/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:14:47 by panger            #+#    #+#             */
/*   Updated: 2023/08/21 18:38:04 by panger           ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		srclen;
	int		i;
	char	*dest;

	srclen = ft_strlen(src);
	i = 0;
	dest = (char *)malloc((srclen + 1) * sizeof(char));
	while (i < srclen)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%s", ft_strdup("TEST1234"));
	return (0);
}
 */