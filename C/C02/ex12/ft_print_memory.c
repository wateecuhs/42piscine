/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:12:53 by panger            #+#    #+#             */
/*   Updated: 2023/08/22 15:54:53 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putadr_hexa(unsigned long adr)
{
	char	*base;
	char	tab[16];
	int		i;

	base = "0123456789abcdef";
	i = 15;
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
	write(1, tab, 16);
}

void	check_end(int count)
{
	while (count < 40)
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
	while (i < 16 && len + i < size)
	{
		ft_putchar(base[(unsigned char)str[i] / 16]);
		ft_putchar(base[(unsigned char)str[i] % 16]);
		count += 2;
		i++;
		if (i % 2 == 0)
		{
			ft_putchar(' ');
			count += 1;
		}
	}
	check_end(count);
}

void	*ft_print_memory(void *adr, unsigned int size)
{
	unsigned int	len;
	unsigned int	j;
	unsigned char	*str;

	len = 0;
	str = (unsigned char *)adr;
	while (len < size)
	{
		ft_putadr_hexa((unsigned long)&str[len]);
		write(1, ": ", 2);
		ft_putstr_hexa((unsigned char *)&str[len], size, len);
		j = 0;
		while (j < 16 && j + len < size)
		{
			if (!(str[j + len] >= 32 && str[j + len] < 127))
				ft_putchar('.');
			else
				ft_putchar(str[j + len]);
			j++;
		}
		len += 16;
		ft_putchar('\n');
	}
	return (adr);
}
