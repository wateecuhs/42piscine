/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:16:26 by panger            #+#    #+#             */
/*   Updated: 2023/08/25 10:14:21 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	read_stdin(void)
{
	char	buf[100];
	int		char_read;

	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(0, buf, 100);
		if (char_read == -1)
			return ;
		buf[char_read] = '\0';
		ft_putstr(buf);
	}
	write(1, "\n", 1);
	return ;
}

void	read_loop(int fd, char *buf, char *str)
{
	int	char_read;

	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(fd, buf, 99);
		if (char_read == -1)
		{
			ft_putstr("cat: ");
			ft_putstr(str);
			write(1, ": ", 2);
			ft_putstr(strerror(errno));
			write(1, "\n", 1);
			return ;
		}
		buf[char_read] = '\0';
		ft_putstr(buf);
	}
}

void	read_file(char *str)
{
	int		fd;
	char	buf[100];
	int		char_read;

	char_read = -1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("cat: ");
		ft_putstr(str);
		write(1, ": ", 2);
		ft_putstr(strerror(errno));
		write(1, "\n", 1);
		return ;
	}
	read_loop(fd, buf, str);
	write(1, "\n", 1);
	close(fd);
	return ;
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		read_stdin();
		return (0);
	}
	else
	{
		while (i < argc)
		{
			read_file(argv[i]);
			i++;
		}
	}
}
