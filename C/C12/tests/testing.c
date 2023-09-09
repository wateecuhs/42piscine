/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:26:09 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/09 16:35:39 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->data);
		head = head->next;
	}
}

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

int	main(int argc, char **argv)
{
	t_list *test;

	if (argc > 1)
	{
		test = ft_list_push_strs(argc - 1, &argv[1]);
		print_list(test);
		printf("\n");
		ft_list_reverse(&test);
		print_list(test);
	}
}