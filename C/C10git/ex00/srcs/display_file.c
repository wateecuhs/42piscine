/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:16:26 by panger            #+#    #+#             */
/*   Updated: 2023/08/31 12:41:21 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i ++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i ++;
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
		ft_putstr_err("Cannot read file.\n");
		return ;
	}
	while (char_read != 0)
	{
		char_read = read(fd, buf, 99);
		if (char_read == -1)
		{
			ft_putstr_err("Cannot read file.\n");
			return ;
		}
		write(1, buf, char_read);
	}
	close(fd);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr_err("File name missing.\n");
		else
			ft_putstr_err("Too many arguments.\n");
		return (0);
	}
	else
	{
		read_file(argv[1]);
	}
	return (1);
}
