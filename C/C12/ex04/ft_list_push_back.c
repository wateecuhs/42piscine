/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:21:58 by panger            #+#    #+#             */
/*   Updated: 2023/09/09 16:45:38 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*head;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
	}
	head = *begin_list;
	while (head->next)
	{
		head = head->next;
	}
	head->next = ft_create_elem(data);
}
