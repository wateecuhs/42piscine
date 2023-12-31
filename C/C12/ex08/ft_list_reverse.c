/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:32:03 by panger            #+#    #+#             */
/*   Updated: 2023/09/09 16:36:09 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int	count;
	t_list	*head;

	count = 0;
	head = begin_list;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*head;
	unsigned int	i;

	i = 0;

	head = begin_list;
	while (i < nbr)
	{
		if (!(head->next))
			return (NULL);
		head = head->next;
		i++;
	}
	return (head);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list			*temp;
	t_list			*newHead;
	int				size;
	unsigned int 	i;

	size = ft_list_size(*begin_list);
	i = 0;
	size --;
	newHead = ft_list_at(*begin_list, size);
	size --;
	temp = newHead;
	while (size >= 0)
	{
		temp->next = ft_list_at(*begin_list, size);
		temp = temp->next;
		size--;
	}
	temp->next = NULL;
	*begin_list = newHead;
}