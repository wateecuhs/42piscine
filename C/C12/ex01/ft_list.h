/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:04:38 by panger            #+#    #+#             */
/*   Updated: 2023/09/09 16:48:13 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>

typedef struct s_list
{
	struct s_list *next;
	void *data;
} t_list;

t_list	*ft_create_elem(void *data)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	ret->data = data;
	ret->next = NULL;
	return (ret);
}

#endif