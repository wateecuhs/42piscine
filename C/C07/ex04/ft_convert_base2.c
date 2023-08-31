/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:49:03 by panger            #+#    #+#             */
/*   Updated: 2023/08/21 16:50:55 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*assign_str(int nbr, char *str, char *base, int neg)
{
	int	i;
	int	baselen;

	baselen = ft_strlen(base);
	i = 0;
	while (nbr >= baselen)
	{
		str[i] = base[nbr % baselen];
		nbr = nbr / baselen;
		i++;
	}
	str[i] = base[nbr % baselen];
	if (neg == -1)
		str[i + 1] = '-';
	return (str);
}
