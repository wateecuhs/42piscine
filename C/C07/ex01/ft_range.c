/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:30:15 by panger            #+#    #+#             */
/*   Updated: 2023/08/21 14:36:28 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (NULL);
	i = 0;
	tab = (int *)malloc((max - min) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (i < (max - min))
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

/* 
#include <stdio.h>
int	main(void)
{
	int	*tab;
	int	i;

	tab = ft_range(14, 22);
	i = 0;
	while (i < 8)
	{
		printf("%d ", tab[i]);
		i++;
	}
}
 */