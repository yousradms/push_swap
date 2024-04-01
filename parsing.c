/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:34:44 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/01 21:58:06 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_double(char **d) {
    
	int e = 0;
	int f;
    while (d[e] && d[e + 1]) {
       f = e + 1;
        while (d[f]) {
            if (ft_atoi(d[e]) == ft_atoi(d[f]))
                return 0; // kin Duplicate 
            f++;
        }
        e++;
    }
    return 1; // makinch duplicates
}
// int check_range(char **d)
// {
// 	int r = 0;
// 	while(d[r])
// 	{
// 		if(ft_atoi(d[r]) >= INT_MIN || ft_atoi(d[r]) <= INT_MAX)
// 			r++;
// 		else
// 			return 0;
// 	}
// 	return 1;
// }
// int check_range(char **d)
// {
//     int r = 0;
//     while (d[r])
// 	{
//         // if (ft_atoi(d[r]) >= INT_MIN && ft_atoi(d[r]) <= INT_MAX) //34567887653358   
//         // if (ft_atoi(d[r]) >= INT_MIN && ft_atoi(d[r]) <= INT_MAX) //   
// 		if(ft_atoi(d[r])!= 9999999999999 && ft_atoi(d[r]) >= INT_MIN && ft_atoi(d[r]) <= INT_MAX)
// 			r++;
//         else
//             return 0; // Out of range
//     }
//     return 1; // All numbers are within range
// }
int check_range(char **d)
{
    int r = 0;
    while (d[r])
	{
        // if (ft_atoi(d[r]) >= INT_MIN && ft_atoi(d[r]) <= INT_MAX) //34567887653358   
        // if (ft_atoi(d[r]) >= INT_MIN && ft_atoi(d[r]) <= INT_MAX) //   
		if(ft_atoi(d[r])!= 9999999999999 && ft_atoi(d[r]) >= INT_MIN && ft_atoi(d[r]) <= INT_MAX)
			r++;
        else
            return 0; // Out of range
    }
    return 1; // All numbers are within range
}

int check_int(char **d)
{
	int r = 0;
	int i = 0;
	
	while(d[r])
	{
		i = 0;
		if(d[r][i] == '-' || d[r][i] == '+')
			i++;
		if(d[r][i] == '\0')
			return 0;
		
		while (d[r][i])
		{
			if (d[r][i] < '0' || d[r][i] > '9') 
			{
                    return 0; // Not an integer
            }
            i++;
        } 
		r++;
	}
	return 1;// this is a integer "your     "
}
int check_empty(char *d) {
	
	int i;
    i = 0;
    while (d[i] && ((d[i] <= 13 && d[i] >= 9) || d[i] == 32))
		i++;
	// i++;
	if(d[i] == '\0')
		return(0);
	return(1);
	
	// {
	// 	if ((d[i] > 13 || d[i] < 9) && d[i] != 32)
	// 	{
	// 		puts("here");
	// 		return 1;
	// 	}
	// 	i++;
	// }

}

void parsing(int ac , char **av, char ***splited)
{
	char *s = NULL;
	int i = 1;
	if(ac < 2)
		return;
	while(av[i])
	{
		if (!check_empty(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		s = ft_strjoin(s, av[i]);
		s = ft_strjoin(s, " ");
		i++;
	}
	i = 0;
	
	*splited = ft_split(s,' ');
	// while(splited[i])
	// {
	// 	printf("%s\n", splited[i]);
	// 	i++;
	// }
	if (!splited || *splited == NULL || *splited[0] == NULL)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (!check_int(*splited) || !check_range(*splited) || check_double(*splited) == 0)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	// crealist(splited);
	// printf("double %splited\n", check_double(splited));
	// printf("int %splited\n", check_int(splited));
	// printf("range %splited\n", check_range(splited));

	
	
	
}