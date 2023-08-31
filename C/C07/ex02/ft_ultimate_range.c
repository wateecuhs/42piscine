/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:49:02 by panger            #+#    #+#             */
/*   Updated: 2023/08/21 18:37:18 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = (int *)malloc((max - min) * sizeof(int));
	if (range == NULL)
		return (-1);
	while (i < (max - min))
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (max - min);
}
/* 
int	main(void)
{
	int	*range;
	ft_ultimate_range(&range, 14, 22);
	int i = 0;
	while (i < 8)
	{
		printf("%d ", range[i]);
		i ++;
	}

} */