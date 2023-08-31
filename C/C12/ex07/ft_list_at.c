/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:56:47 by panger            #+#    #+#             */
/*   Updated: 2023/08/23 09:31:10 by panger           ###   ########.fr       */
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
		if (head->next == '\0')
			return (NULL);
		head = head->next;
		i++;
	}
	return (head);
}