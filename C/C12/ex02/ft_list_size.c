/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:20:07 by panger            #+#    #+#             */
/*   Updated: 2023/08/21 09:21:35 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;
	t_list	*head;

	count = 0;
	head = begin_list;
	while (head != '\0')
	{
		head = head->next;
		count++;
	}
	return (count);
}
