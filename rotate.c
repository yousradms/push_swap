/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:31:27 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 06:08:32 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = *stack;
	tmp2 = *stack;
	*stack = (*stack)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->next = NULL;
}

void	ra(t_node **stack_a, int print)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b, int print)
{
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a && (*stack_a)->next) || (*stack_b && (*stack_b)->next))
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
		write(1, "rr\n", 3);
	}
}
