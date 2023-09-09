/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:55:58 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/09 16:58:49 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->next, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return ((t_list *)0);
}