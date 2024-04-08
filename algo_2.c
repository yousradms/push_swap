/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 05:35:05 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 05:35:50 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_node **stack, t_node *max_node)
{
	t_node	*t1;
	int		i;

	t1 = (*stack);
	i = 0;
	while (t1)
	{
		if (t1->content == max_node->content)
			return (i);
		i++;
		t1 = t1->next;
	}
	return (0);
}

t_node	*get_max(t_node **stack)
{
	t_node	*max_node;
	t_node	*current;

	if (*stack == NULL)
		return (0);
	current = *stack;
	max_node = current;
	while (current != NULL)
	{
		if (current->content > max_node->content)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*get_bef_max(t_node **stack, t_node *max)
{
	t_node	*b_max;
	t_node	*current;

	if (*stack == NULL)
		return (0);
	current = *stack;
	b_max = NULL;
	while (current != NULL)
	{
		if (current->content < max->content
			&& (b_max == NULL || current->content > b_max->content))
			b_max = current;
		current = current->next;
	}
	if (b_max == NULL)
		return (max);
	return (b_max);
}

void	from_b_to_a1(t_node **stack_a, t_node **stack_b,
		t_node *max_node, int max_index)
{
	if (max_index <= ft_lstsize(*stack_b) / 2)
		while ((*stack_b)->content != max_node->content)
			rb(stack_b, 1);
	else
		while ((*stack_b)->content != max_node->content)
			rrb(stack_b, 1);
	pa(stack_a, stack_b);
	if ((*stack_a)->next && (*stack_a)->next->content < (*stack_a)->content)
		sa(stack_a, 1);
}

void	from_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*max_node;
	t_node	*bef_max_node;
	int		max_index;
	int		bef_max_index;

	while (ft_lstsize(*stack_b) > 0)
	{
		max_node = get_max(stack_b);
		max_index = get_max_index(stack_b, max_node);
		bef_max_node = get_bef_max(stack_b, max_node);
		bef_max_index = get_max_index(stack_b, bef_max_node);
		if (ft_abs(ft_lstsize(*stack_b) / 2 - max_index)
			< ft_abs(ft_lstsize(*stack_b) / 2 - bef_max_index))
		{
			if (bef_max_index <= ft_lstsize(*stack_b) / 2)
				while ((*stack_b)->content != bef_max_node->content)
					rb(stack_b, 1);
			else
				while ((*stack_b)->content != bef_max_node->content)
					rrb(stack_b, 1);
			pa(stack_a, stack_b);
		}
		from_b_to_a1(stack_a, stack_b, max_node, max_index);
	}
}
