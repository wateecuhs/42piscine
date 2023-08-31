/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:07:37 by panger            #+#    #+#             */
/*   Updated: 2023/08/13 17:53:50 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && (i < n))
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i ++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
/* 
#include <string.h>
#include <stdio.h>

int main(void)
{
	printf("%d\n",ft_strncmp("Test12", "Test12", 5));
	printf("%d",strncmp("Test12", "Test12", 5));
} */