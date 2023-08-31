/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:10:36 by panger            #+#    #+#             */
/*   Updated: 2023/08/25 10:01:41 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str);
void	ft_putchar(char c);

void	check_end(int count)
{
	while (count < 39)
	{
		ft_putchar(' ');
		count++;
	}
}

void	ft_putstr_hexa(unsigned char *str, unsigned int size, unsigned int len)
{
	char	*base;
	int		i;
	int		count;

	base = "0123456789abcdef";
	i = 0;
	count = 0;
	while (i < 16 && len + i < size - 1)
	{
		ft_putchar(base[(unsigned char)str[i + 1] / 16]);
		ft_putchar(base[(unsigned char)str[i + 1] % 16]);
		ft_putchar(base[(unsigned char)str[i] / 16]);
		ft_putchar(base[(unsigned char)str[i] % 16]);
		fflush(stdout);
		count += 4;
		i += 2;
		if (i % 2 == 0 && i != 16)
		{
			ft_putchar(' ');
			count += 1;
		}
	}
	check_end(count);
	ft_putchar('\n');
}

void	ft_putadr_hexa(unsigned long adr)
{
	char	*base;
	char	tab[7];
	int		i;

	base = "0123456789abcdef";
	i = 6;
	while (adr >= 16 && i > 0)
	{
		tab[i] = base[adr % 16];
		i--;
		adr = adr / 16;
	}
	tab[i--] = base[adr % 16];
	while (i >= 0)
	{
		tab[i] = '0';
		i--;
	}
	write(1, tab, 7);
}

char	*ft_hexdump(void *adr, unsigned int size, int stdinval)
{
	unsigned int	len;
	unsigned char	*str;

	len = 0;
	str = (unsigned char *)adr;
	while (len < size)
	{
		if (stdinval != -1)
		{
			ft_putadr_hexa(stdinval);
			stdinval += 16;
		}
		else
			ft_putadr_hexa((unsigned long)&str[len] - (unsigned long)&str[0]);
		write(1, " ", 1);
		ft_putstr_hexa((unsigned char *)&str[len], size, len);
		len += 16;
	}
	if (stdinval == -1)
	{
		ft_putadr_hexa((unsigned long)&str[size] - (unsigned long)&str[0]);
		ft_putchar('\n');
	}
	return (adr);
}
