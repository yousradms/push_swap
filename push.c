/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:54:21 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 06:06:57 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*head1;
	t_node	*head2;
	t_node	*tmp;

	if (!(*stack_b))
		return ;
	head1 = *stack_a;
	head2 = *stack_b;
	tmp = head2;
	head2 = head2->next;
	tmp->next = head1;
	head1 = tmp;
	tmp = NULL;
	*stack_a = head1;
	*stack_b = head2;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!(*stack_b))
		return ;
	write(1, "pa\n", 3);
	push(stack_a, stack_b);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (!(*stack_a))
		return ;
	write(1, "pb\n", 3);
	push(stack_b, stack_a);
}
