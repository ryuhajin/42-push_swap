/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:16:33 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 22:12:28 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap_bonus.h"

int checker_input_s (char * line, t_list * checker_stack_A, t_list * checker_stack_B)
{
	if (line[1] == 'a')
	{	
		checker_cmd_sa(checker_stack_A);
		return success;
	}
	else if (line[1] == 'b')
	{	
		checker_cmd_sb(checker_stack_B);
		return success;
	}
	else if (line[1] == 's')
	{
		checker_cmd_ss(checker_stack_A, checker_stack_B);
		return success;
	}
	return failed;
}

int checker_input_p (char * line, t_list * checker_stack_A, t_list * checker_stack_B)
{
	if (line[1] == 'a')
	{	
		checker_cmd_pa(checker_stack_B, checker_stack_A);
		return success;
	}
	else if (line[1] == 'b')
	{	
		checker_cmd_pb(checker_stack_A, checker_stack_B);
		return success;
	}
	return failed;
}

int checker_input_r (char * line, t_list * checker_stack_A, t_list * checker_stack_B)
{
	if (line[1] == 'a')
	{	
		checker_cmd_ra(checker_stack_A);
		return success;
	}
	else if (line[1] == 'b')
	{	
		checker_cmd_rb(checker_stack_B);
		return success;
	}
	else if (line[1] == 'r')
	{
		checker_cmd_rr(checker_stack_A, checker_stack_B);
		return success;
	}
	return failed;
}

int checker_input_rr (char * line, t_list * checker_stack_A, t_list * checker_stack_B)
{
	if (line[2] == 'a')
	{	
		checker_cmd_rra(checker_stack_A);
		return success;
	}
	else if (line[2] == 'b')
	{	
		checker_cmd_rrb(checker_stack_B);
		return success;
	}
	else if (line[2] == 'r')
	{
		checker_cmd_rrr(checker_stack_A, checker_stack_B);
		return success;
	}
	return failed;
}

int checker_cmd_check (char * line, t_list * checker_stack_A, t_list * checker_stack_B)
{
	int size;
	int flag;
	
	flag = failed;
	size = ft_strlen(line);
	if (line[0] == 's' && size == 3)
		flag = checker_input_s(line, checker_stack_A, checker_stack_B);
	else if (line[0] == 'p' && size == 3)
		flag = checker_input_p(line, checker_stack_A, checker_stack_B);
	else if (line[0] == 'r' && size == 3)
		flag = checker_input_r(line, checker_stack_A, checker_stack_B);
	else if (line[0] == 'r' && line[1] == 'r' && size == 4)
		flag = checker_input_rr(line, checker_stack_A, checker_stack_B);
	return flag;
}
