/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:19:42 by dayou             #+#    #+#             */
/*   Updated: 2023/07/21 23:27:48 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int numbers_space_check(char c)
{
    if (c >= '0' && c <= '9')
        return success;
    if (c == ' ')
        return success;
    return failed;
}

int slipt_ready(int argc, char ** argv)
{
    int i;
    int j;
    i = 0;
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
        }
        i++;
    }
    return success;
}

int atoi_ready(int argc, char ** argv, char *** split)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        split[j] = ft_split(argv[i], ' ');
        if(split[j] == NULL)
            return failed;
        i++;
        j++;
    }
    split[argc] = NULL;
    return success;
}

int list_ready(int argc, char *** split)
{
    
}

int input_ready(int argc, char ** argv)
{
    char ** split[argc];

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