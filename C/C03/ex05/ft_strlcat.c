/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:44:34 by panger            #+#    #+#             */
/*   Updated: 2023/08/14 13:34:17 by panger           ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	ret_val;

	ret_val = ft_strlen(src);
	len = ft_strlen(dest);
	i = 0;
	if (size < len)
		ret_val = ret_val + size;
	else
		ret_val = ret_val + len;
	while (src[i] && len + i < size - 1 && size != '\0')
	{
		dest[len + i] = src[i];
		i ++;
	}
	dest[len + i] = '\0';
	return (ret_val);
}
/* 
#include <stdio.h>
int	main(void)
{
	char test[25] = "test";

	printf("%d\n", ft_strlen(test));
	printf("%d", ft_strlen("test"));
} */
