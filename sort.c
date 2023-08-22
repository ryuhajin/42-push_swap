/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:21:37 by dayou             #+#    #+#             */
/*   Updated: 2023/08/22 16:57:42 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void ft_swap (int * start, int * end)
{
	int temp;
	temp = *start;
	*start = *end;
	*end = temp;
}

int stack_A_sort (t_list * stack_A)
{
	int arr[stack_A->size];
    t_node * temp;
    int i;

	i = 0;
    temp = stack_A->head->next;
    while (i < stack_A->size)
    {
        arr[i] = temp->value;
        i++;
        temp = temp->next;
    }
	printf_sort(arr, stack_A->size);
	// printf("sort start\n");
	quick_sort(arr, 0, (stack_A->size)-1);
	// printf_sort(arr, stack_A->size);
	if (sort_check(arr, stack_A))
		return failed; // 0 == 정렬되어 있으면 그리디 x 바로 종료
	stack_A_indexing (arr, stack_A);
	return success; // 1 == 그리디 시작
}

void quick_sort (int * arr, int start, int end)
{
	int pivot;
	int i;
	int j;

	pivot = start;
	i = start +1;
	j = end;
	if (start >= end)
		return;
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
	quick_sort(arr, start, j-1);
	quick_sort(arr, j+1, end);
}

void printf_sort (int * arr, int size)
{
	int i;
	i = 0;
	while (i < size)
	{	
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int sort_check (int * arr, t_list * stack_A)
{
	int i;
	t_node * temp;

	i = 0;
	temp = stack_A->head->next;
	while (i < stack_A->size)
	{
		if (arr[i] != temp->value)
			return failed;
		i++;
		temp = temp->next;
	}
	return success;
}

void stack_A_indexing (int * arr, t_list * stack_A)
{
	int i;
	t_node * temp;

	i = 0;
	while (i < stack_A->size)
	{
		temp = search_node(stack_A, arr[i]);
		temp->value = i;
		i++;
	}
}
