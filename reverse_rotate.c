/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:29:27 by ydoumas           #+#    #+#             */
/*   Updated: 2024/02/29 19:14:17 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node *tmp1;
	t_node *tmp2;
	t_node *tmp3;
	
	tmp1 = *stack;
	tmp2 = tmp1;
	tmp3  = tmp1;
	while(tmp1->next->next)
	{
		tmp1 = tmp1->next;
	}
	tmp3 = tmp1->next;
	tmp1->next = NULL;
	tmp3->next = tmp2;
	*stack = tmp3;
	tmp2 = NULL;
	tmp1 = NULL;
	tmp3 = NULL;
}
void	rra(t_node **stack_a, int print)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	reverse_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}
void	rrb(t_node **stack_b, int print)
{
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_b);
	if (print)
		write(1, "rra\n", 4);	
}
void	rrr(t_node **stack_a , t_node **stack_b)
{
	if ((*stack_a && (*stack_a)->next) || (*stack_b && (*stack_b)->next))
	{
		rra(stack_a, 0);
		rrb(stack_b, 0);
		write(1, "rrr\n", 4);
	}
}
