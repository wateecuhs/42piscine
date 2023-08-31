/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:50:00 by panger            #+#    #+#             */
/*   Updated: 2023/08/25 12:04:14 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int		ft_strlen(char *str);
int		read_input_bytes(int argc, char **argv);
int		read_input_value(char *str);
void	ft_putstr(char *str);
void	read_stdin(void);
void	ft_putstr_var(char *str, char *var);

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

void	find_start(char *str, int bytes)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
		i++;
	i = i - bytes;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*get_str(char *str)
{
	char	*ret;
	int		fd;
	int		char_read;
	int		len;	

	len = count_file(str);
	if (len == -1)
	{
		ft_putstr_var("tail: cannot open '#' for reading: ", str);
		ft_putstr(strerror(errno));
		write(1, "\n", 1);
		return (NULL);
	}
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

void	main_loop(int argc, char **argv, int bytes)
{
	int		i;
	char	*str;

	i = 1;
	while (i < argc)
	{
		if ((argv[i][0] == '-' && argv[i][1] == 'c')
			|| (argv[i - 1][0] == '-' && argv[i - 1][1] 
			&& ft_strlen(argv[i - 1]) == 2))
		{
			i++;
			continue ;
		}
		str = get_str(argv[i]);
		if (str == NULL)
		{
			i++;
			continue ;
		}
		find_start(str, bytes);
		i++;
		free(str);
	}
}

int	main(int argc, char **argv)
{
	int		bytes;
	int		i;
	if (argc < 2)
	{
		read_stdin();
	}
	i = 1;
	bytes = read_input_bytes(argc, argv);
	if (bytes <= 0)
	{
		return (0);
	}
	main_loop(argc, argv, bytes);
	return (1);
}
