/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:50:35 by panger            #+#    #+#             */
/*   Updated: 2023/08/25 12:08:05 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void	read_stdin(void)
{
	char	buf[100];
	int		char_read;

	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(0, buf, 99);
		if (char_read == -1)
			return ;
		buf[char_read] = '\0';
	}
	return ;
}
