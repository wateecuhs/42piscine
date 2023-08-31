/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:28:31 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 21:12:34 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_stdin(char *dict)
{
	char	buf[500];
	int		char_read;
	char	*temp;

	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(0, buf, 499);
		if (char_read == -1)
			return ;
		buf[char_read - 1] = '\0';
		if (check_number(buf))
		{
			temp = atoa(buf);
			if (is_printable(temp, dict))
				split_number(temp, dict);
			else
				write(1, "Dict Error\n", 11);
			free(temp);
		}
		else
			write(1, "Error\n", 6);
	}
	write(1, "\n", 1);
	return ;
}
