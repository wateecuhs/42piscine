/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 02:01:04 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/07 22:57:03 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	struct node *next;
	unsigned int	val;

} t_node;

t_node	*ft_create_elem(int data)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	ret->val = data;
	ret->next = NULL;
	return (ret);
}

t_node *str_to_node(char *s)
{
	int	i;
	t_node *list1;
	t_node *parser1;

	i = 0;
	while (s[i])
		i++;
	i--;
	list1 = ft_create_elem(s[i] - 48);
	i--;
	parser1 = list1;
	while (i >= 0)
	{
		parser1->next = ft_create_elem(s[i] - 48);
		parser1 = parser1->next;
		i--;
	}
	return (list1);
}

void	print_node(t_node *head)
{
	int	i;
	char *str;
	t_node *headhead;

	i = 0;
	headhead = head;
	while (head)
	{
		i++;
		head = head->next;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (headhead)
	{
		str[i] = headhead->val + '0';
		headhead = headhead->next;
		i--;
	}
	printf("%s\n", str);
	free(str);
}

void	free_node(t_node *node)
{
	t_node *head;
	while (node)
	{
		head = node;
		node = node->next;
		free(head);
	}
}

t_node *order_node(t_node *newListHead)
{
	t_node *newList;
	int	temp;
	
	newList = newListHead;
	while (newList)
	{
		if (newList->val > 9)
		{
			temp = newList->val / 10;
			newList->val = newList->val % 10;
			if (newList->next)
			{
				newList->next->val += temp;
			}
			else
			{
				newList->next = ft_create_elem(temp);
			}
		}
		newList = newList->next;
	}
	return (newListHead);
}

void multiply(char *s1, char *s2)
{
	t_node *list1;
	t_node *list2;
	t_node *newList;
	t_node *newListHead;
	t_node *parser1;
	t_node *parser2;
	int	j;
	int	depth;
	int	adding;
	int	temp;

	list1 = str_to_node(s1);
	list2 = str_to_node(s2);

	parser1 = list2;
	depth = 0;
	newListHead = ft_create_elem(0);
	newList = newListHead;
	while (parser1)
	{
		parser2 = list1;
		newList = newListHead;
		j = 0;
		while (j < depth)
		{
			if (newList->next)
				newList = newList->next;
			else
			{
				newList->next = ft_create_elem(0);
				newList = newList->next;
			}
			j++;
		}
		while (parser2)
		{
			newListHead = order_node(newListHead);
			adding = (parser2->val * parser1->val);
			adding += newList->val;
			newList->val = adding;
			if (newList->val > 9)
			{
				temp = newList->val / 10;
				newList->val = newList->val % 10;
				if (newList->next)
				{
					newList->next->val += temp;
				}
				else
				{
					newList->next = ft_create_elem(temp);
				}
			}
			if (parser2->next)
			{
				if (newList->next)
				{
					newList = newList->next;
				}
				else
				{
					newList->next = ft_create_elem(0);
					newList = newList->next;
				}
			}
			parser2 = parser2->next;
		}
		parser1 = parser1->next;
		depth++;
	}
	newListHead = order_node(newListHead);
	print_node(newListHead);
	free_node(list1);
	free_node(list2);
	free_node(newListHead);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		multiply(argv[1], argv[2]);
}