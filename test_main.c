/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:57:30 by dayou             #+#    #+#             */
/*   Updated: 2023/08/27 21:41:57 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int word_check (char * str, int i)
{
	int temp;

	temp = i;
	printf( "temp: %d, str[i]: %c\n", temp, str[temp]);
	if (str[temp] == '\0')
		return failed;
	if (str[temp] == '+' || str[temp] == '-')
		temp++;
	printf( "temp: %d, str[i]: %c\n", temp, str[temp]);
	if (str[temp] == ' ' || str[temp] == '+' || str[temp] == '-' || str[temp] == '\0')
		return failed;
	while (str[temp] != ' ' && str[temp] != '\0')
	{
		if (str[temp] >= '0' && str[temp] <= '9')
			temp++;
		else
			return failed;
	}
	return temp;
}

int str_check (char * accessx_np)
{
	int i;
	int check;

	i = 0;
	while (argv[i])
	{
		printf( "i: %d, argv[i]: %s\n", i, argv+i);
		check = 0;
		while(argv[i] == ' ')
			i++;
		check = word_check(argv, i);
		if (check == 0)
			return failed;
		else
			i = check;
		i++;
	}
	return success;
}

int split_ready(int argc, char ** argv)
{
    int i;
    int j;

    i = 1;
	j = 0;
    while (i < argc)
    {
        if (argv[i][j] == '\0')
            return failed;
		if (!str_check(argv[i])) // 문자열 시작점
			return failed;
        i++;
    }
    return success;
}

int main(int argc, char * argv[])
{
	int a;
	a = split_ready(argc, argv);
	// int i = 0;
	// while (i < argc)
	// {
	// 	printf("%d, %s\n",i, argv[i]);
	// 	++i;
	// }
	
}
