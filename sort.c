/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:21:37 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 19:29:42 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

void	ft_swap(int *start, int *end)
{
	int	temp;

	temp = *start;
	*start = *end;
	*end = temp;
}

int	stack_a_sort(t_list *stack_a)
{
	int		*arr;
	t_node	*temp;
	int		i;

	arr = (int *)malloc(sizeof(int) * stack_a->size);
	i = 0;
	stack_a->idx_size = stack_a->size;
	temp = stack_a->head->next;
	while (i < stack_a->size)
	{
		arr[i] = temp->value;
		i++;
		temp = temp->next;
	}
	quick_sort(arr, 0, (stack_a->size) - 1);
	if (sort_check(arr, stack_a))
	{
		free(arr);
		fclear_list(stack_a);
		return (failed);
	}
	stack_a_indexing(arr, stack_a);
	free(arr);
	return (success);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = start;
	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		if (i > j)
			ft_swap(&arr[pivot], &arr[j]);
		else
			ft_swap(&arr[i], &arr[j]);
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int	sort_check(int *arr, t_list *stack_a)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack_a->head->next;
	while (i < stack_a->size)
	{
		if (arr[i] != temp->value)
			return (failed);
		i++;
		temp = temp->next;
	}
	return (success);
}

void	stack_a_indexing(int *arr, t_list *stack_a)
{
	int		i;
	t_node	*temp;

	i = 0;
	while (i < stack_a->size)
	{
		temp = search_node(stack_a, arr[i]);
		temp->value = i;
		i++;
	}
}
