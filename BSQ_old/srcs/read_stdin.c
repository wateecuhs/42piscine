/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:46:10 by panger            #+#    #+#             */
/*   Updated: 2023/08/28 18:10:38 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_stdin(void)
{
	char	buf[10];
	int		char_read;
	int		fd;

	fd = open("map", O_CREAT | O_WRONLY | O_TRUNC);
	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(0, buf, 10);
		if (char_read == -1)
			return ;
		buf[char_read] = '\0';
		write(fd, buf, char_read);
	}
	close(fd);
	return ;
}
