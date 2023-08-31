/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:31:45 by panger            #+#    #+#             */
/*   Updated: 2023/08/25 12:04:57 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*print_loop_m(char *temp, int c, int c_count, int *print_count)
{
	if (c_count == 0)
		ft_hexdump(temp, (c - (c % 16)), *print_count);
	else
		ft_hexdump_c(temp, (c - (c % 16)), c_count, *print_count);
	*print_count += c - (c % 16);
	temp = &temp[c - (c % 16)];
	return (temp);
}

void	read_loop(char *temp, int c_count)
{
	int		char_read;
	char	buf[100];
	int		print_count;
	int		c;

	char_read = -1;
	print_count = 0;
	c = 0;
	while (char_read != 0)
	{
		char_read = read(0, buf, 99);
		if (char_read == -1)
			return ;
		buf[char_read] = '\0';
		c += char_read;
		if (c >= 16)
		{
			temp = print_loop_m(ft_strcat(temp, buf), c, c_count, &print_count);
			c = c % 16;
		}
		else if (char_read > 0)
			temp = ft_strcat(temp, buf);
	}
}

void	read_stdin(int c_count)
{
	int		char_read;
	int		c;
	int		print_count;
	char	*temp;

	temp = (char *)malloc(sizeof(char) + 1);
	temp[0] = '\0';
	c = 0;
	char_read = -1;
	print_count = 0;
	read_loop(temp, c_count);
	write(1, "\n", 1);
	return ;
}

char	*get_str(char *str)
{
	char	*ret;
	int		fd;
	int		char_read;
	int		count;
	int		len;	

	len = read_file(str);
	if (len == -1)
		return (NULL);
	ret = (char *)malloc(len * sizeof(char) + 1);
	char_read = -1;
	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}
	char_read = read(fd, ret, len);
	if (char_read == -1)
		return (NULL);
	count += char_read;
	ret[len] = '\0';
	close(fd);
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		read_stdin(0);
	}
	else
		ft_read_input(argv, argc);
}
