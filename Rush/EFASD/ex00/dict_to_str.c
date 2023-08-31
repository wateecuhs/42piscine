/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:35:06 by panger            #+#    #+#             */
/*   Updated: 2023/08/27 18:30:20 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_file(char *str)
{
	int		fd;
	char	buf[100];
	int		char_read;
	int		count;

	char_read = -1;
	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (char_read != 0)
	{
		char_read = read(fd, buf, 99);
		if (char_read == -1)
			return (-1);
		count += char_read;
	}
	close(fd);
	return (count);
}

char	*get_str(char *str)
{
	char	*ret;
	int		fd;
	int		char_read;
	int		len;	

	len = count_file(str);
	if (len == -1)
		return (NULL);
	ret = (char *)malloc((len + 1) * sizeof(char));
	char_read = -1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	char_read = read(fd, ret, len);
	if (char_read == -1)
		return (NULL);
	ret[len] = '\0';
	close(fd);
	return (ret);
}
