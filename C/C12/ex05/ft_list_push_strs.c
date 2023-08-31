/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:33:59 by panger            #+#    #+#             */
/*   Updated: 2023/08/23 09:28:48 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int	i;
	t_list	*begin_list;
	t_list	*temp;

	i = 1;
	begin_list = ft_create_elem(strs[0]);
	while (i < size)
	{
		temp = ft_create_elem(strs[i]);
		temp->next = begin_list;
		begin_list = temp;
		i++;
	}
	return (begin_list);
}