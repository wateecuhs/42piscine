/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:44:26 by panger            #+#    #+#             */
/*   Updated: 2023/09/09 16:49:10 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*temp;

	while(begin_list)
	{
		temp = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = temp;
	}
}