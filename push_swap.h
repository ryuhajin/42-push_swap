/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:54:33 by dayou             #+#    #+#             */
/*   Updated: 2023/08/22 20:41:34 by dayou            ###   ########.fr       */
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

// push_swap_utlis
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

//input_utils.c
int numbers_space_check(char c);
int split_ready(int argc, char ** argv);
int atoi_ready(int argc, char ** argv, char ** split[]);
int input_ready(int argc, char ** argv, char ** split[], t_list * list);

//input_utils2.c
void split_free(char ** split);
void split_clear(int argc, char ** split[]);
size_t	count_word(char const *str, char c);
void	copy_words(char **split, char const *str, char c, size_t size);
size_t	alloc_words(char **split, char const *str, char c, size_t size);
char	**ft_split(char const *str, char c);

//input_utils3.c
long long	ft_atoi(const char *str);
int search_same_value(t_list * list, int value);
int list_ready(int argc, char ** split[], t_list * list);

//command_utils.c
int make_stack (t_list * stack_A, t_list * stack_B);
void cmd_sa (t_list * stack_A);
void cmd_sb (t_list * stack_B);
void cmd_ss (t_list * stack_a, t_list * stack_b);
void cmd_pa (t_list * stack_a, t_list * stack_b);
void cmd_pb (t_list * stack_a, t_list * stack_b);
void cmd_ra (t_list * stack_a);
void cmd_rb (t_list * stack_b);
void cmd_rr (t_list * stack_a, t_list * stack_b);
void cmd_rra (t_list * stack_a);
void cmd_rra (t_list * stack_a);
void cmd_rrb (t_list * stack_b);
void cmd_rrr (t_list * stack_a, t_list * stack_b);

//sort.c
void ft_swap (int * start, int * end);
int stack_A_sort (t_list * stack_A);
void quick_sort (int * arr, int start, int end);
void printf_sort (int * arr, int size);
int sort_check (int * arr, t_list * stack_A);
void stack_A_indexing (int * arr, t_list * stack_A);

//greedy.c
void A_to_B (t_list * stack_A, t_list * stack_B);
void min_to_stack_B (int min_pivot, t_list * stack_A, t_list * stack_B);
void middle_to_stack_B (int max_pivot, t_list * stack_A, t_list * stack_B);
void max_to_stack_B (int input_max, t_list * stack_A, t_list * stack_B);
void stack_A_in_three_node (t_list * stack_A);

#endif