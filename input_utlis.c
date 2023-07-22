/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:19:42 by dayou             #+#    #+#             */
/*   Updated: 2023/07/22 17:43:45 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int numbers_space_check(char c)
{
    if (c >= '0' && c <= '9')
        return success;
	else if (c == '-' || c == '+')
		return success;
    return failed;
}
int slipt_ready(int argc, char ** argv)
{
    int i;
    int j;
	int cnt;
	
    i = 0;
	cnt = 0;
    if (argc == 1)
        return failed;
    while (argv[i])
    {
        j = 0;
        if (argv[i][j] == '\0')
            return failed;
        while (argv[i][j])
        {
			if (numbers_space_check(argv[i][j]) == failed)
				return failed;
			j++;
        }
        i++;
    }
    return success;
}

int atoi_ready(int argc, char ** argv, char ** split[])
{
	char ** temp;
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        temp = ft_split(argv[i], ' ');
        if(temp == NULL)
            return failed;
		split[j] = temp;
        i++;
        j++;
    }
    split[j] = NULL;
    return success;
}

int input_ready(int argc, char ** argv)
{
    char ** split[argc -1];

    if (split_ready(argv))
    {
        if (atoi_ready(argc, argv, split))
        {
            if (list_ready(argc, split))
            {

            }
        }
    }
    
    return failed;
}
