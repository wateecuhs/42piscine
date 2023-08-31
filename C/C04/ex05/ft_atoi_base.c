/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:06:09 by panger            #+#    #+#             */
/*   Updated: 2023/08/15 15:01:16 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
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
		if (base[i] == '+' || base[i] == '-' 
			|| (base[i] <= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		i ++;
	}
	return (1);
}

int	check_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i ++;
	}
	return (-1);
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
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (check_base(str[i], base) != -1)
	{
		tot = tot * base_len + check_base(str[i], base);
		i ++;
	}
	return (sign * tot);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d", ft_atoi_base("  ++----+--+gerne8eq45", "engr"));	
} */