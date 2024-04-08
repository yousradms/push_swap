/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:25:25 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 06:10:15 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_node **stack, int print)
{
	if (!((*stack)) && !((*stack)->next))
		return ;
	swap(stack);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack, int print)
{
	if (!((*stack)) || !((*stack)->next))
		return ;
	swap(stack);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a && (*stack_a)->next) || (*stack_b && (*stack_b)->next))
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
		write(1, "ss\n", 3);
	}
}
