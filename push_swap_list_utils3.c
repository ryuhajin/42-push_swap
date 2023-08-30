/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:32:04 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 19:03:47 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

t_node	*push_front(t_list *list, int value)
{
	return (next_insert_node(list, list->head->next, value));
}

t_node	*push_back(t_list *list, int value)
{
	return (prev_insert_node(list, list->head->next, value));
}

t_node	*search_node(t_list *list, int value)
{
	t_node	*temp;

	temp = list->head->next;
	if (temp->value == value)
		return (temp);
	temp = list->head->next->next;
	while (temp != list->head->next)
	{
		if (temp->value == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	remove_node(t_list *list, t_node *n)
{
	if (n == list->head)
		return ;
	if (list->size == 1)
	{
		del_node(n);
		list->head->next = list->head;
		list->head->prev = list->head;
		list->size--;
		return ;
	}
	if (n == list->head->next)
	{
		list->head->next = list->head->next->next;
	}
	n->prev->next = n->next;
	n->next->prev = n->prev;
	list->size--;
	del_node(n);
}

void	clear_list(t_list *list)
{
	t_node	*node;
	t_node	*temp;

	if (list->head == list->head->next)
		return ;
	node = list->head->next->prev;
	while (node != list->head->next)
	{
		remove_node(list, node);
		temp = list->head->next->prev;
		node = temp;
	}
	del_node(list->head->next);
	list->head->next = NULL;
	list->size--;
}
