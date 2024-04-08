/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:51:17 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 06:58:35 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	tmp[3];

	i = 0;
	tmp[2] = 0;
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
		tmp[1] = tmp[2];
		tmp[2] = tmp[2] * 10 + str[i] - 48;
		tmp[0] = (tmp[2] - (str[i] - 48)) / 10;
		if (tmp[0] != tmp[1])
			return (9999999999999);
		i++;
	}
	return (tmp[2] * sign);
}
