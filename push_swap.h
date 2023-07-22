/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:54:33 by dayou             #+#    #+#             */
/*   Updated: 2023/07/22 15:13:22 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef enum e_status
{
    //malloce_fail = -1
	failed = 0,
	success = 1
}	t_status;
typedef struct Node
{
    struct Node * next;
    struct Node * prev;
    int value;
} t_node;
typedef struct List
{
    t_node * head;
    int size;
} t_list;

//리스트 init, print_list
t_list * make_list(void);
t_node * make_node(int numbers);
void del_node(t_node * node);
void print_list(t_list * list);

// 삽입, 추가, 이동
t_node * first_add_node (t_list * list, int value);
void splice(t_list * list, t_node * a, t_node * b, t_node * x);
void next_move_node(t_list * list, t_node * this, t_node * self, t_node * x);
void prev_move_node(t_list * list, t_node * this, t_node * self, t_node * x);
t_node * next_insert_node(t_list * list, t_node * x, int value);
t_node * prev_insert_node(t_list * list, t_node * x, int value);
t_node * push_Front(t_list * list, int value);
t_node * push_Back(t_list * list, int value);

// 탐색
t_node * search_node(t_list * list, int value);

// 삭제
void remove_node(t_list * list, t_node * n);
void clear_list(t_list * list);
void fclear_list(t_list * list);

#endif