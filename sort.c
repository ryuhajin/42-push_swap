/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:21:37 by dayou             #+#    #+#             */
/*   Updated: 2023/08/21 17:11:48 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int * stack_A_sort (t_list * stack_A)
{
    int arr[stack_A->size];
    t_node * temp;
    int i;

    temp = stack_A->head->next->next;
    while (i < stack_A->size)
    {
        arr[i] = temp->value;
        i++;
        temp = temp->next;
    }
}

void quick_sort (int * arr)
{
    
}
