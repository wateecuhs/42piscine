/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:06:29 by panger            #+#    #+#             */
/*   Updated: 2023/08/25 12:04:36 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	read_file(char *str)
{
	int		fd;
	char	buf[100];
	int		char_read;
	int		count;

	char_read = -1;
	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
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

int	get_c_count(char **strs, int size)
{
	int	i;
	int	c_mode;

	i = 1;
	c_mode = 0;
	while (i < size)
	{
		if (ft_strcmp(strs[i], "-C") == 0)
			c_mode += 1;
		i++;
	}
	if (c_mode + 1 == size)
	{
		read_stdin(c_mode);
	}
	return (c_mode);
}

void	read_input2(char *str, int c_mode)
{
	char	*str2;

	if (ft_strcmp(str, "-C") != 0)
	{
		str2 = get_str(str);
		if (str2 == NULL)
		{
			ft_putstr_var("hexdump: #: ", str);
			ft_putstr(strerror(errno));
			write (1, "\n", 1);
			return ;
		}
		if (c_mode >= 1)
		{
			ft_hexdump_c(str2, ft_strlen(str2), c_mode, -1);
			free(str2);
		}
		else
		{
			ft_hexdump(str2, ft_strlen(str2), -1);
			free(str2);
		}
		return ;
	}
}

void	ft_read_input(char **strs, int size)
{
	int		i;
	int		c_mode;

	i = 1;
	c_mode = get_c_count(strs, size);
	i = 1;
	while (i < size)
	{
		read_input2(strs[i], c_mode);
		i++;
	}
}
