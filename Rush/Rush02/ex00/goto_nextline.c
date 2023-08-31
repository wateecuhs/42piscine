/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_nextline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:22:32 by brappo            #+#    #+#             */
/*   Updated: 2023/08/27 19:22:55 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	goto_nextline(int *i, char *dict)
{
	int	new_i;

	while (dict[*i] && dict[*i] != '\n')
		*i = *i + 1;
	if (dict[*i] == '\n')
		*i = *i + 1;
	new_i = *i;
	while (dict[new_i] == ' ' || dict[new_i] == '\n')
	{
		if (dict[new_i] == '\n')
			*i = new_i;
		new_i++;
	}
}
