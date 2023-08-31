/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:10:38 by panger            #+#    #+#             */
/*   Updated: 2023/08/31 16:47:06 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	check_end_c(int count)
{
	while (count < 50)
	{
		ft_putchar(' ');
		count++;
	}
}

void	ft_putstr_hexa_c(unsigned char *str, unsigned int s, unsigned int len)
{
	char	*base;
	int		i;
	int		count;

	base = "0123456789abcdef";
	i = 0;
	count = 0;
	while (i < 16 && len + i < s)
	{
		ft_putchar(base[(unsigned char)str[i] / 16]);
		ft_putchar(base[(unsigned char)str[i] % 16]);
		count += 2;
		i++;
		ft_putchar(' ');
		count ++;
		if (i == 8)
		{
			ft_putchar(' ');
			count ++;
		}
	}
	check_end_c(count);
}

void	print_loop(int len, unsigned int size, unsigned char *str)
{
	unsigned int	j;

	j = 0;
	while (j < 16 && j + len < size)
	{
		if (!(str[j + len] >= 32 && str[j + len] < 127))
			ft_putchar('.');
		else
			ft_putchar(str[j + len]);
		j++;
	}
}

void	loop_dump(unsigned char *str, int len, int size, int *stdinval)
{
	if (*stdinval != -1)
	{
		ft_putadr_hexa(*stdinval);
	}
	else
		ft_putadr_hexa((unsigned long)&str[len] - (unsigned long)&str[0]);
	write(1, "  ", 2);
	ft_putstr_hexa_c((unsigned char *)&str[len], size, len);
	write(1, "|", 1);
	print_loop(len, size, str);
	write(1, "|", 1);
	ft_putchar('\n');
}

void	*ft_hexdump_c(void *adr, unsigned int size, int c, int stdinval)
{
	unsigned int	len;
	unsigned char	*str;
	int				loop_count;
	int				combo;

	len = 0;
	combo = 0;
	str = (unsigned char *)adr;
	while (len < size)
	{
		if (combo_checker(str, &len, size, &combo) == 0)
			continue ;
		loop_count = 0;
		while (loop_count++ < c)
			loop_dump(str, len, size, &stdinval);
		if (stdinval != -1)
			stdinval += 16;
		len += 16;
	}
	if (stdinval == -1)
	{
		ft_putadr_hexa((unsigned long)&str[size] - (unsigned long)&str[0]);
		ft_putchar('\n');
	}
	return (adr);
}
