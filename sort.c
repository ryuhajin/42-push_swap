/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:21:37 by dayou             #+#    #+#             */
/*   Updated: 2023/08/21 19:16:29 by dayou            ###   ########.fr       */
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

void stack_A_sort (t_list * stack_A)
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
	printf("sort start\n");
	quick_sort(arr, 0, (stack_A->size)-1);
	printf_sort(arr, stack_A->size);
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
