/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:18:55 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 16:25:38 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int line_by_line_check(char *dict)
{
	int	i;
	int	j;
	char	*temp;
	char	*temp2;

	i = 0;
	while (dict[i])
	{
		if (i == 0 || dict[i - 1] == '\n')
		{
			temp = atoa(&dict[i]);
			j = i + 1;
			while (dict[j])
			{
				if (dict[j - 1] == '\n')
				{
					temp2 = atoa(&dict[j]);
					if (strcmp(temp, temp2) == 0)
					{
						free(temp);
						free(temp2);
						return (0);
					}
					free(temp2);
				}
				j++;
			}
			free(temp);
		}
		i++;
	}
	return (1);
}