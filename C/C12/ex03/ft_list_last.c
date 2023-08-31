/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:08 by panger            #+#    #+#             */
/*   Updated: 2023/08/21 09:21:28 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_last(t_list *begin_list)
{
	t_list	*head;

	head = begin_list;
	while (head->next != '\0')
	{
		head = head->next;
	}
	return (head);
}
