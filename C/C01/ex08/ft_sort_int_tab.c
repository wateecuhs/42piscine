/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:48:48 by panger            #+#    #+#             */
/*   Updated: 2023/08/09 16:11:43 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	b;

	i = 0;
	while (i < size)
	{
		b = i + 1;
		while (b < size)
		{
			if (tab[i] > tab[b])
			{
				temp = tab[i];
				tab[i] = tab[b];
				tab[b] = temp;
			}
			b ++;
		}
		i++;
	}
}
