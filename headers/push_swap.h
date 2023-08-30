/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:54:33 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 14:19:40 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // delete

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
	int idx_size;
} t_list;

// push_swap_list_utils //
t_node * make_node(int numbers);
t_list * make_list(void);
t_node * first_add_node (t_list * list, int value);
void del_node(t_node * node);
void print_list(t_list * list);

// push_swap_list_utils 2 //
void splice(t_list * list, t_node * a, t_node * b, t_node * x);
void next_move_node(t_list * list, t_node * this, t_node * self, t_node * x);
void prev_move_node(t_list * list, t_node * this, t_node * self, t_node * x);
t_node * next_insert_node(t_list * list, t_node * x, int value);
t_node * prev_insert_node(t_list * list, t_node * x, int value);

// push_swap_list_utils 3 //
t_node * push_Front(t_list * list, int value);
t_node * push_Back(t_list * list, int value);
t_node * search_node(t_list * list, int value);
void remove_node(t_list * list, t_node * n);
void clear_list(t_list * list);

// push_swap_list_utils 4 //
int make_stack (t_list ** stack_A, t_list ** stack_B);
void fclear_list(t_list * list);
void fclear_2_lists(t_list * list, t_list * list2);

// input_utils //
int split_start(int argc, char ** argv, char ** splits[]);
void all_clear (int argc, char ** splits[], t_list * stack_A, t_list * stack_B);
int atoi_start (int argc, char ** splits[], t_list * stack_A);
int input_check (int argc, char * argv[], t_list * stack_A, t_list * stack_B);

// input_utils 2 //
int number_check (char * str);
int search_same_value(t_list * list, int value);
int same_range_check (char * str, t_list * stack_A);
long long	ft_atoi(const char *str);
char	**ft_split(char const *str, char c);

// input_utils 3 //
void split_free(char ** split);
void split_clear(int argc, char ** split[]);
size_t	count_word(char const *str, char c);
void	copy_words(char **split, char const *str, char c, size_t size);
size_t	alloc_words(char **split, char const *str, char c, size_t size);

// command_utils //
void cmd_sa (t_list * stack_A);
void cmd_sb (t_list * stack_B);
void cmd_ss (t_list * stack_a, t_list * stack_b);
void cmd_pa (t_list * stack_b, t_list * stack_a);
void cmd_pb (t_list * stack_a, t_list * stack_b);

// command_utils 2 //
void cmd_ra (t_list * stack_a);
void cmd_rb (t_list * stack_b);
void cmd_rr (t_list * stack_a, t_list * stack_b);

// command_utils 3 //
void cmd_rra (t_list * stack_a);
void cmd_rrb (t_list * stack_b);
void cmd_rrr (t_list * stack_a, t_list * stack_b);

// sort //
void ft_swap (int * start, int * end);
int stack_A_sort (t_list * stack_A);
void quick_sort (int * arr, int start, int end);
int sort_check (int * arr, t_list * stack_A);
void stack_A_indexing (int * arr, t_list * stack_A);

// solution //
void stack_A_in_two_node (t_list * stack_A);
void stack_A_in_three_node (t_list * stack_A);
void stack_A_in_four_node (t_list * stack_A, t_list * stack_B);
int stack_A_size_too_small (t_list * stack_A, t_list * stack_B);

// solution 2 //
void find_max_idx (t_list * stack_A, t_list * stack_B);
void	move_range_to_b(int min, int max, t_list *stack_a, t_list *stack_b);
void stack_A_B_setting (t_list * stack_A, t_list * stack_B);
void stack_A_round (t_list * stack_A, int * temp_total);
void stack_B_round (t_list * stack_B, t_node * temp, int * temp_total, int idx);

//solution 3 //
void r_compare (int * temp_total, int idx);
void cmd_count (int * temp_total);
void copy_cmd(int * temp_total, int * min_cmd);
void cnt_optimization (int * temp_total, int * min_cmd);

//solution 4//
void cmd_reset (int * arr);
void one_round_count (t_list * stack_A, t_list * stack_B, int * min_cmd);
void cmd_call (t_list * stack_A, t_list * stack_B, int * min_cmd);
void last_stack_A_sort (t_list * stack_A);
void solution_commander (t_list * stack_A, t_list * stack_B);

#endif
