/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:35:32 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/01 22:52:10 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, char c)
{
	printf("Stack %c :\n", c);

	t_node	*curr = stack;
	printf("size: %d\n", ft_lstsize(stack));
	while (curr)
	{
		printf("%d, %d\n", curr->content, curr->index);
		curr = curr->next;
	}
	printf("\n\n");
}

void index_stack_1(t_node **stack)
{
	t_node *t1;
	t_node *t2;
	t1 = (*stack);
	while(t1)
	{
		t2 = (*stack);
		int j = 0;
		while(t2)
		{
			if(t1->content > t2->content)
				j++;
			t2 = t2->next;
		}
		t1->index = j;
		t1 = t1->next;
	}
}

void index_stack_2(t_node **stack)
{
	t_node *t1;
	t1 = (*stack);
	int	i;

	i = 0;
	while(t1)
	{
		t1->index = i;
		i++;
		t1 = t1->next;
	}
}

// 1- index the stack b
// 2- while stack b isn't empty, do this each time you loop over the stack:
// * index b
// * find the index of the max
// * if the index is <= (size / 2) do rb, ch7al mn merra ? dak l'index li l9iti
// * if the index is > (size / 2) do rrb, ch7al mn merra ? size - l'index dyal max
// * mn be3d pa
int index_max(t_node **stack)
{
	if (*stack == NULL) {
        return 0;
    }
    int max_value ;
    int max_index;
    t_node *current = *stack;
    max_value = current->content;
    while (current != NULL) {
        if (current->content > max_value) {
            max_value = current->content;
            max_index = current->index;
        }
        current = current->next;
    }

    return max_index;
}
void from_b_to_a(t_node **stack_a, t_node **stack_b)
{
	int	max_index;
	int	i;
	
	while(ft_lstsize(*stack_b) > 0)
	{
		index_stack_2(stack_b);
		max_index = index_max(stack_b);
		i = 0;
		if (max_index <= ft_lstsize(*stack_b) / 2)
		{
			while (i < max_index)
			{
				rb(stack_b, 1);
				i++;
			}
		}
		else
		{
			while (i < ft_lstsize(stack_b) - max_index)
			{
				rrb(stack_b, 1);
				i++;
			}
		}
		pa(stack_a, stack_b);
	}
}



void algo_ch(t_node **stack_a, t_node **stack_b)
{
	int i;
	int div;
	int size;

	while(ft_lstsize(*stack_a) > 3)
	{
		(i = 0, div = (ft_lstsize(*stack_a)) / 3);
		size = ft_lstsize(*stack_b);
		while (i <= div && ft_lstsize((*stack_a)) > 3)
		{
			if ((*stack_a)->index <= ((div / 2) + size))
			{
				pb(stack_a,stack_b);
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
int check_sorted_stack(t_node **stack_a)
{
	
	t_node *curr;
	curr = *stack_a;
	while (curr && curr->next)
    {
        if (curr->content > curr->next->content)
            return 0;
        curr = curr->next; 
    }
    return 1;
}
void stack_3(t_node **stack_a)
{
	t_node *head;
	head = *stack_a;
	if(head->content > head->next->content
		&& head->content > head->next->next->content)
	{
		ra(stack_a, 1);
		head = *stack_a;
	}
	if(head->next->content > head->content && head->next->content > head->next->next->content)
	{
		
		rra(stack_a, 1);
		head = *stack_a;
	}
	if(head->content > head->next->content)
		sa(stack_a, 1);
}
void stack_5(t_node **stack_a,t_node **stack_b)
{
	t_node *head = *stack_a;
	t_node *hea;
	while(ft_lstsize(*stack_a)>3)
	{
		head = *stack_a;
		if(head->index == 0 || head->index == 1)
			pb(stack_a,stack_b);
		else
			ra(stack_a,1);
	}
	hea = *stack_b;
	if(hea->content < hea->next->content)
		sb(stack_b,1);
	stack_3(stack_a);
	pa(stack_a,stack_b);
	pa(stack_a,stack_b);
	
	
}

		
	


int main(int ac, char **av)
{
	char	**splited;
	// ft_split return: [*str = "21", *str = "431", "214"];

	t_node	*a;
	t_node *b;
	splited = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	parsing(ac, av, &splited);
	a = imp_lis(splited);
	if (check_sorted_stack(&a))
		exit(0);
	if (ft_lstsize(a) == 3)
		(stack_3(&a), exit(1));
	//index_stack_1(&a);
	if (ft_lstsize(a) == 5)
		(stack_5(&a,&b), exit(1));
	algo_ch(&a,&b);
	//print_stack(a, 'A');
	//print_stack(b, 'B');
	
	
}


