/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:46:10 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 13:18:06 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_stdin(void)
{
	char	buf[100];
	int		char_read;
	int		fd;

	fd = open("pierre_luy_2709_1009", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(0, buf, 100);
		if (char_read == -1)
			return ;
		write(fd, buf, char_read);
	}
	close(fd);
	return ;
}
