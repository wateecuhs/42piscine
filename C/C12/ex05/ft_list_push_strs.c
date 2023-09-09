/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:33:59 by panger            #+#    #+#             */
/*   Updated: 2023/09/09 16:14:24 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	ret->data = data;
	ret->next = NULL;
	return (ret);
} */

t_list	*ft_list_push_strs(int size, char **strs)
{
	int	i;
	t_list	*begin_list;
	t_list	*temp;

	i = 1;
	begin_list = ft_create_elem(strs[0]);
	while (i < size)
	{
		temp = ft_create_elem(strs[i]);
		temp->next = begin_list;
		begin_list = temp;
		i++;
	}
	return (begin_list);
}
/* 
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_list *test;

	if (argc > 2)
	{
		test = ft_list_push_strs(argc - 1, &argv[1]);
		while (test)
		{
			printf("%s\n", (char *)test->data);
			test = test->next;
		}
	}
} */