/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:51:17 by ydoumas           #+#    #+#             */
/*   Updated: 2024/02/25 16:41:10 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	c;
	int	i;
	int		sign;

	i = 0;
	c = 0;
	sign = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		long tmpc;
		tmpc = c;
		c = c * 10 + str[i] - 48;
		long tmp = (c  - (str[i] - 48))/10;
		// printf("tmp : %zu   c: %zu\n",tmp,tmpc);
		if(tmp != tmpc)
		{
			return 9999999999999;
		}

		
		// if (c >= __LONG_MAX__ && sign == 1)
		// 	return (-1);
		// else if (c >= __LONG_MAX__ && sign == -1)
		// 	return (0);
		// if ((c > INT_MAX && sign == 1) || (c < INT_MIN && sign == -1))
        //     return 0; 
		i++;
	}
	return (c * sign);
}




