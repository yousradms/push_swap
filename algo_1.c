/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 05:09:56 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 05:36:27 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_ch_1(t_node **stack_a, t_node **stack_b, int divider, int div)
{
	int	i;
	int	size;

	while (ft_lstsize(*stack_a) > 3)
	{
		i = 0;
		div = (ft_lstsize(*stack_a)) / divider;
		size = ft_lstsize(*stack_b);
		while (i <= div && ft_lstsize((*stack_a)) > 3)
		{
			if ((*stack_a)->index <= ((div / 2) + size))
			{
				pb(stack_a, stack_b);
				rb(stack_b, 2);
				i++;
			}
			else if ((*stack_a)->index <= (div + size))
			{
				pb(stack_a, stack_b);
				i++;
			}
			else
				ra(stack_a, 3);
		}
	}
}

void	algo_ch(t_node **stack_a, t_node **stack_b)
{
	int	div;
	int	divider;

	div = 0;
	if (ft_lstsize(*stack_a) > 200)
		divider = 5;
	else
		divider = 3;
	algo_ch_1(stack_a, stack_b, divider, div);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}
