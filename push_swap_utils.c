/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:32:18 by dayou             #+#    #+#             */
/*   Updated: 2023/07/28 19:37:51 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node * make_node(int numbers) //빈 노드 생성
{
    t_node * node;
    node = (t_node *)malloc(sizeof(t_node));
    if (node == NULL)
        return NULL;
    node->value = numbers;
    node->next = node;
    node->prev = node;
    return node;
}

t_list * make_list(void) // 리스트 생성 , 헤드==더미노드 설정.
{
    t_list * list;
    t_node * dummy_node;
    list = (t_list *)malloc(sizeof(t_list));
    if (list == NULL)
        return NULL;
    dummy_node = make_node(0);
    if(dummy_node == NULL)
    {
        free(list);
        return NULL;
    }
    list->head = dummy_node;
    list->size = 0;
    return list;
}

t_node * first_add_node (t_list * list, int value)
{
    t_node * node;
    node = make_node(value);
    if(node == NULL)
        return NULL;
    list->head->next = node;
    list->head->prev = node;
    list->size++;
    return node;
}

void del_node(t_node * node)
{
    // printf("del : %p\n", node);
    free(node);
}

void print_list(t_list * list)
{
    t_node * temp;
    if (list->head->next == list->head)
        return;
	printf("%d ", list->head->next->value);
    temp = list->head->next->next;
    while (temp != list->head->next)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\nsize: %d\n", list->size);
}

void splice(t_list * list, t_node * a, t_node * b, t_node * x) // x 앞에 a~b까지 잘라넣기. x -> a ~ b -> x.n
{
    t_node * a_p;
    t_node * b_n;
    t_node * x_n;
    if (a == list->head || b == list->head || x == list->head)
        return;
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

void next_move_node(t_list * list, t_node * this, t_node * self, t_node * x)
{
    splice(list, this, self, x); //x 앞으로 node(자기 자신) 이동
}

void prev_move_node(t_list * list, t_node * this, t_node * self, t_node * x)
{
    x = x->prev;
    splice(list, this, self, x); //x 뒤로 node(자기 자신)이동
}

t_node * next_insert_node(t_list * list, t_node * x, int value) //x 노드 앞에 추가
{
    t_node * node;
    if(list->head == list->head->next)
    {
        node = first_add_node(list, value);
        if (node == NULL)
            return NULL;
        return node;
    }
    else 
    {
        node = make_node(value);
        if(node == NULL)
            return NULL;
    }
    next_move_node(list, node, node, x);
    list->size++;
    return node;
}

t_node * prev_insert_node(t_list * list, t_node * x, int value) //x 노드 뒤에 추가
{
    t_node * node;
    if (list->head == list->head->next)
    {
        node = first_add_node(list, value);
        if (node == NULL)
            return NULL;
        return node;
    }
    node = make_node(value);
    if(node == NULL)
        return NULL;
    prev_move_node(list, node, node, x);
    list->size++;
    return node;
}

t_node * push_Front(t_list * list, int value) //헤드 앞 추가 (head->next)
{
    return next_insert_node(list, list->head->next, value);
}

t_node * push_Back(t_list * list, int value) //헤드 뒤에 추가 (head->prev) (가장 마지막 노드)
{
    return prev_insert_node(list, list->head->next, value);
}

t_node * search_node(t_list * list, int value)
{
    t_node * temp;
    temp = list->head->next;
    if(temp->value == value)
        return temp;
    temp = list->head->next->next;
    while(temp != list->head->next)
    {
        if(temp->value == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void remove_node(t_list * list, t_node * n)
{
    if (n == list->head)
        return;
	if (list->size == 1)
	{
		del_node(n);
		list->head->next = list->head;
		list->head->prev = list->head;
		list->size--;
		return;
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

void clear_list(t_list * list)
{
    t_node * node;
    t_node * temp;

	if (list->head == list->head->next)
		return;
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

void fclear_list(t_list * list)
{
    clear_list(list);
    free(list->head);
    list->head = NULL;
    free(list);
}

// void	check_leak(void)
// {
// 	system("leaks --list a.out");
// }

// int main(void)
// {
//     t_list * list = make_list();
//     push_Back(list, 1);
//     push_Back(list ,2);
//     print_list(list);
//     // fclear_list(list);
//     // atexit(check_leak);
//     return 0;
// }
