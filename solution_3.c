/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:31:44 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 22:42:35 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/push_swap.h"

void rr_compare (int * temp_total)
{
	if (temp_total[1] == temp_total[3]) //ra[0], rb[3], rr[5]
	{
		temp_total[5] = temp_total[1];
		temp_total[1] = 0;
		temp_total[3] = 0;
	}
	else if (temp_total[1] > temp_total[3])
	{
		temp_total[5] = temp_total[3];
		temp_total[1] = temp_total[1] - temp_total[3];
		temp_total[3] = 0;
	}
	else
	{	
		temp_total[5] = temp_total[1];
		temp_total[3] = temp_total[3] - temp_total[1];
		temp_total[1] = 0;
	}	
}

void rrr_compare (int * temp_total) //rra[2], rrb[4], rrr[6]
{
	if (temp_total[2] == temp_total[4])
	{
		temp_total[6] = temp_total[2];
		temp_total[2] = 0;
		temp_total[4] = 0;
	}
	else if (temp_total[2] > temp_total[4])
	{
		temp_total[6] = temp_total[4];
		temp_total[2] = temp_total[2] - temp_total[4];
		temp_total[4] = 0;
	}
	else
	{	
		temp_total[6] = temp_total[2];
		temp_total[4] = temp_total[4] - temp_total[2];
		temp_total[2] = 0;
	}	
}

void cmd_count (int * temp_total)
{
	int i;
	int cmd_cnt;
	
	i = 1;
	cmd_cnt = 0;
	while (i < 7)
	{
		cmd_cnt += temp_total[i];
		i++;
	}
	temp_total[7] = cmd_cnt;
}

void copy_cmd(int * temp_total, int * min_cmd)
{
	int i;

	i = 0;
	while (i < 8)
	{
		min_cmd[i] = temp_total[i];
		i++;
	}	
}

void cnt_optimization (int * temp_total, int * min_cmd)
{
	rr_compare(temp_total);
	rrr_compare(temp_total);
	cmd_count(temp_total);
	if (temp_total[7] < min_cmd[7])
		copy_cmd(temp_total, min_cmd);
}
