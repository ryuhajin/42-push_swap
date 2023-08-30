/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:30:29 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 22:50:35 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

t_node	*make_node(int numbers)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = numbers;
	node->next = node;
	node->prev = node;
	return (node);
}

t_list	*make_list(void)
{
	t_list	*list;
	t_node	*dummy_node;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	dummy_node = make_node(0);
	if (dummy_node == NULL)
	{
		free(list);
		return (NULL);
	}
	list->head = dummy_node;
	list->size = 0;
	list->idx_size = 0;
	return (list);
}

t_node	*first_add_node(t_list *list, int value)
{
	t_node	*node;

	node = make_node(value);
	if (node == NULL)
		return (NULL);
	list->head->next = node;
	list->head->prev = node;
	list->size++;
	return (node);
}

void	del_node(t_node *node)
{
	free(node);
}

void	print_list(t_list *list)
{
	t_node	*temp;

	if (list->head->next == list->head)
		return ;
	temp = list->head->next->next;
	while (temp != list->head->next)
	{
		temp = temp->next;
	}
}
