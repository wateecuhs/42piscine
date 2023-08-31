/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:55:01 by panger            #+#    #+#             */
/*   Updated: 2023/08/22 15:12:26 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		check_base(char c, char *base);

char	*assign_str(int nbr, char *str, char *base, int neg);

int		ft_strlen(char *str);

int	valid_base(char *base)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (base[i])
	{
		b = i + 1;
		while (base[b])
		{
			if (base[i] == base[b])
				return (0);
			b ++;
		}
		if (base[i] == '+' || base[i] == '-' 
			|| ft_strlen(base) == 1 || ft_strlen(base) == 0)
			return (0);
		i ++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	tot;
	int	base_len;

	base_len = ft_strlen(base);
	i = 0;
	sign = 1;
	tot = 0;
	if (valid_base(base) == 0)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (check_base(str[i], base) != -1)
	{
		tot = tot * base_len + check_base(str[i++], base);
	}
	return (sign * tot);
}

char	*int_to_base(int nbr, char *base)
{
	int		i;
	int		baselen;
	char	*str;
	int		nbr_cpy;
	int		neg;

	i = 0;
	neg = 1;
	if (nbr < 0)
	{
		neg = -1;
		nbr = -nbr;
	}
	nbr_cpy = nbr;
	baselen = ft_strlen(base);
	while (nbr_cpy >= baselen)
	{
		nbr_cpy = nbr_cpy / baselen;
		i ++;
	}
	str = (char *)malloc((i + 1 + (neg < 0)) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (assign_str(nbr, str, base, neg));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value;
	char	*str;
	int		i;
	int		strlen;
	char	temp;

	if (valid_base(base_from) == 0 || valid_base(base_to) == 0)
		return (NULL);
	value = ft_atoi_base(nbr, base_from);
	str = int_to_base(value, base_to);
	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen)
	{
		temp = str[i];
		str[i] = str[strlen - 1];
		str[strlen - 1] = temp;
		i ++;
		strlen --;
	}
	return (str);
}

int	main(int argc, char **argv)
{
    (void)argc;
    // (void)argv;
    // printf("%s",ft_convert_base("ff", "0123456789abcdef", "01"));
    printf("%s",ft_convert_base(argv[1], argv[2], argv[3]));
    //ex : ./a.out 1458 0123456789 0123456789abcdef
}
