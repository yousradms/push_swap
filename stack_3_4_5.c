/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 05:43:55 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 06:44:03 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (!(*stack))
		return ;
	while ((*stack) != NULL)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		free(temp);
	}
	free(*stack);
	*stack = NULL;
}

int	check_sorted_stack(t_node **stack_a)
{
	t_node	*curr;

	curr = *stack_a;
	while (curr && curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	stack_3(t_node **stack_a)
{
	t_node	*head;

	head = *stack_a;
	if (ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a, 4);
		return ;
	}
	if (head->content > head->next->content
		&& head->content > head->next->next->content)
	{
		ra(stack_a, 1);
		head = *stack_a;
	}
	if (head->next->content > head->content
		&& head->next->content > head->next->next->content)
	{
		rra(stack_a, 1);
		head = *stack_a;
	}
	if (head->content > head->next->content)
		sa(stack_a, 1);
}

void	stack_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;

	head = *stack_a;
	while (ft_lstsize(*stack_a) > 3)
	{
		head = *stack_a;
		if (head->index == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}
	stack_3(stack_a);
	pa(stack_a, stack_b);
}

void	stack_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;
	t_node	*hea;

	head = *stack_a;
	while (ft_lstsize(*stack_a) > 3)
	{
		head = *stack_a;
		if (head->index == 0 || head->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}
	hea = *stack_b;
	if (hea->content < hea->next->content)
		sb(stack_b, 1);
	stack_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
