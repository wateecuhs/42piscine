/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:07:37 by panger            #+#    #+#             */
/*   Updated: 2023/08/11 10:05:04 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			if (s1[i] < s2[i])
				return (-1);
		}
		i ++;
	}
	if (s1[i])
		return (1);
	if (s2[i])
		return (-1);
	return (0);
}

/* 

#include <string.h>
#include <stdio.h>
int main(void)
{
	printf("%d",ft_strcmp("Test1234", "Test1424"));
	printf("%d",strcmp("Test1234", "Test1424"));
}
*/