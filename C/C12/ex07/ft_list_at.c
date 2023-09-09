/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:56:47 by panger            #+#    #+#             */
/*   Updated: 2023/09/09 16:16:51 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

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