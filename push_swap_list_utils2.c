/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:31:06 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 17:16:56 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

void	splice(t_list *list, t_node *a, t_node *b, t_node *x)
{
	t_node	*a_p;
	t_node	*b_n;
	t_node	*x_n;

	if (a == list->head || b == list->head || x == list->head)
		return ;
	a_p = a->prev;
	b_n = b->next;
	a_p->next = b_n;
	b_n->prev = a_p;
	x_n = x->next;
	x_n->prev = b;
	b->next = x_n;
	a->prev = x;
	x->next = a;
}

void	next_move_node(t_list *list, t_node *this, t_node *self, t_node *x)
{
	splice(list, this, self, x);
}

void	prev_move_node(t_list *list, t_node *this, t_node *self, t_node *x)
{
	x = x->prev;
	splice(list, this, self, x);
}

t_node	*next_insert_node(t_list *list, t_node *x, int value)
{
	t_node	*node;

	if (list->head == list->head->next)
	{
		node = first_add_node(list, value);
		if (node == NULL)
			return (NULL);
		return (node);
	}
	else
	{
		node = make_node(value);
		if (node == NULL)
			return (NULL);
	}
	next_move_node(list, node, node, x);
	list->size++;
	return (node);
}

t_node	*prev_insert_node(t_list *list, t_node *x, int value)
{
	t_node	*node;

	if (list->head == list->head->next)
	{
		node = first_add_node(list, value);
		if (node == NULL)
			return (NULL);
		return (node);
	}
	node = make_node(value);
	if (node == NULL)
		return (NULL);
	prev_move_node(list, node, node, x);
	list->size++;
	return (node);
}
