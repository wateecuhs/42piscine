/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:32:03 by panger            #+#    #+#             */
/*   Updated: 2023/08/23 09:54:51 by panger           ###   ########.fr       */
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
	while (head != '\0')
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
		if (head->next == '\0')
			return (NULL);
		head = head->next;
		i++;
	}
	return (head);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list			*temp;
	unsigned int	size;
	unsigned int 	i;

	size = ft_list_size(*begin_list);
	i = 0;
	while (i < size / 2)
	{
	}
}