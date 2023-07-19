/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:54:33 by dayou             #+#    #+#             */
/*   Updated: 2023/07/06 21:42:27 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct Node
{
    t_node * next;
    t_node * prev;
    int value;
    //함수 포인터 print_value(node 값 출력)
} t_node;

typedef struct List
{
    t_node * head; //원형 연결 리스트는 항상 마지막 노드를 가르켜야 한다.
    //head == 마지막 노드 주소. head->prev == 첫번째 노드 주소
    //함수 포인터 iter(리스트 값 출력), size(노드가 몇 개 있는지)
} t_list;


#endif