/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:26:42 by panger            #+#    #+#             */
/*   Updated: 2023/08/30 14:34:11 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	get_bytes(long int nb)
{
	int bytes;

	bytes = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;	
		bytes++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		bytes++;
	}
	return (bytes);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int	bytes;
	int		i;
	long int nbr;
	
	nbr = nb;
	bytes = get_bytes(nbr);
	str = (char *)malloc(sizeof(char ) * (bytes + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	i = bytes - 1;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	str[bytes] = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	printf("%s \n", ft_itoa(atoi(argv[1])));
}