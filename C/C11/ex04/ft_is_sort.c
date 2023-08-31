/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:53:48 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 12:46:09 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort_left(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if ((*f)(tab[i], tab[j]) > 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_sort_right(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;

	i = length - 1;
	while (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if ((*f)(tab[i], tab[j]) > 0)
			{
				return (0);
			}
			j--;
		}
		i--;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_sort_left(tab, length, f) == 1 
		|| ft_is_sort_right(tab, length, f) == 1)
		return (1);
	return (0);
}
