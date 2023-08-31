/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:28:31 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 18:29:06 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_stdin(char *dict)
{
	char	buf[100];
	int		char_read;
	char	*temp;

	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(0, buf, 99);
		if (char_read == -1)
			return ;
		buf[char_read - 1] = '\0';
		temp = atoa(buf);
		split_number(temp, dict);
		free (temp);
	}
	write(1, "\n", 1);
	return ;
}
