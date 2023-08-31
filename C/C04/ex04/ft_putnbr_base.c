/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:56:11 by panger            #+#    #+#             */
/*   Updated: 2023/08/23 18:23:21 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	valid_base(char *base)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		b = i + 1;
		while (base[b])
		{
			if (base[i] == base[b])
				return (0);
			b ++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i ++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nb;

	base_len = ft_strlen(base);
	if (valid_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	nb = nbr;
	if (nb > base_len - 1)
	{
		ft_putnbr_base(nb / base_len, base);
		ft_putnbr_base(nb % base_len, base);
	}
	else
		ft_putchar(base[nb]);
}
/* 
#include <stdlib.h>
int	main()
{
	char *str;
	str ="01234";
	ft_putnbr_base(5, str);
	return (0);
} */