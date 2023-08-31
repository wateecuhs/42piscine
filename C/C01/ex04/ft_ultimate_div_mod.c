/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:58:02 by panger            #+#    #+#             */
/*   Updated: 2023/08/09 16:10:02 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div_temp;
	int	mod_temp;

	div_temp = *a / *b;
	mod_temp = *a % *b;
	*a = div_temp;
	*b = mod_temp;
}
