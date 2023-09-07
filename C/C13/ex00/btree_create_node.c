/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:33:02 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/06 02:08:36 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_btree
{
	struct s_btree *left;
	struct s_btree *right;
	void *item;
}	t_btree;

t_btree *btree_create_node(void *item)
{
	t_btree *node;

	node = (t_btree *)malloc(sizeof(t_btree) * 1);
	if (!node)
		return (NULL);
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}