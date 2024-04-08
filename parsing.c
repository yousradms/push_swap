/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:34:44 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 06:41:28 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **d)
{
	int	e;
	int	f;

	e = 0;
	while (d[e] && d[e + 1])
	{
		f = e + 1;
		while (d[f])
		{
			if (ft_atoi(d[e]) == ft_atoi(d[f]))
				return (0);
			f++;
		}
		e++;
	}
	return (1);
}

int	check_range(char **d)
{
	int	r;

	r = 0;
	while (d[r])
	{
		if (ft_atoi(d[r]) != 9999999999999
			&& ft_atoi(d[r]) >= INT_MIN && ft_atoi(d[r]) <= INT_MAX)
			r++;
		else
			return (0);
	}
	return (1);
}

int	check_int(char **d)
{
	int	r;
	int	i;

	r = 0;
	while (d[r])
	{
		i = 0;
		if (d[r][i] == '-' || d[r][i] == '+')
			i++;
		if (d[r][i] == '\0')
			return (0);
		while (d[r][i])
		{
			if (d[r][i] < '0' || d[r][i] > '9')
				return (0);
			i++;
		}
		r++;
	}
	return (1);
}

int	check_empty(char *d)
{
	int	i;

	i = 0;
	if (!d || !d[0])
		return (0);
	while (d[i] && ((d[i] <= 13 && d[i] >= 9) || d[i] == 32))
		i++;
	if (d[i] == '\0')
		return (0);
	return (1);
}

void	free_splited(char **numbs)
{
	int	i;

	if (!numbs || !numbs[0])
		return ;
	i = 0;
	while (numbs[i])
	{
		free(numbs[i]);
		i++;
	}
	free(numbs);
	numbs = NULL;
}
