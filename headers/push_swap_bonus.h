/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:25:48 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 21:03:07 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h> // delete

# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

typedef enum e_read_status
{
	read_failed = -1,
	read_EOF = 0,
}		t_read_status;

typedef enum e_new_line_status
{
	no_new_line = 0,
	make_new_line = 1,
	line_malloc_failed = 2
}		t_make_line_status;

// input bonus //
int checker_input_s (char * line, t_list * checker_stack_A, t_list * checker_stack_B);
int checker_input_p (char * line, t_list * checker_stack_A, t_list * checker_stack_B);
int checker_input_r (char * line, t_list * checker_stack_A, t_list * checker_stack_B);
int checker_input_rr (char * line, t_list * checker_stack_A, t_list * checker_stack_B);
int checker_cmd_check (char * line, t_list * checker_stack_A, t_list * checker_stack_B);

// input bonus 2//
int checker_sort_check (t_list * checker_stack_A);
int line_check (t_list * checker_stack_A, t_list * checker_stack_B);

// utils_bonus //
size_t	ft_strlen(const char *s);
ssize_t	read_file(int fd, char **line, char remainder[][BUFFER_SIZE + 1]);
char	*read_flag_check(ssize_t flag, char *line);
char	*get_next_line(int fd);

// utils_bonus 2 //
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2, ssize_t size);
size_t	ft_strlcpy(char *dest, char *src);
ssize_t	find_newline(char *buff, ssize_t *size);
ssize_t	remainder_find_n(int fd, char **line, char remainder[][BUFFER_SIZE + 1]);

// command_bonus //
void checker_cmd_sa (t_list * stack_A);
void checker_cmd_sb (t_list * stack_B);
void checker_cmd_ss (t_list * stack_a, t_list * stack_b);
void checker_cmd_pa (t_list * stack_b, t_list * stack_a);
void checker_cmd_pb (t_list * stack_a, t_list * stack_b);

// cmd b 2 //
void checker_cmd_ra (t_list * stack_a);
void checker_cmd_rb (t_list * stack_b);
void checker_cmd_rr (t_list * stack_a, t_list * stack_b);

// cmd b 3 //
void checker_cmd_rra (t_list * stack_a);
void checker_cmd_rrb (t_list * stack_b);
void checker_cmd_rrr (t_list * stack_a, t_list * stack_b);

#endif
