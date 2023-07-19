/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:32:18 by dayou             #+#    #+#             */
/*   Updated: 2023/07/07 00:22:47 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list * list){ //head는 list의 마지막 노드
    t_node * temp = list->head->next; //마지막 노드가 가르키는 것은 첫번째 노드
    t_node * end = list->head->next;
    if(temp == NULL)
        return NULL;
    printf("%d ", temp->value);
    temp = temp->next;
    while (temp != end)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void splice(t_node * self, t_node * a, t_node * b, t_node * n)
{
    if(self == NULL || a == NULL || b == NULL || n == NULL)
        return;
    t_node * a_prev = a->prev;
    t_node * b_next = b->next;
    t_node * n_next = n->next;

    //자르는 연산
    a_prev->next = b_next;
    b_next->prev = a_prev;

    //n 뒤에 a, b 삽입하기
    n_next->prev = b;
    b->next = n_next;
    a->prev = n;
    n->next = a;
}