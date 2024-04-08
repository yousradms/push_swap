/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:35:32 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 06:44:39 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parsing1(char **av)
{
	char	*s;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 1;
	while (av[i])
	{
		if (!check_empty(av[i]))
			(write(2, "Error\n", 6), exit(1));
		tmp2 = s;
		tmp = ft_strjoin(s, av[i]);
		free(tmp2);
		s = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (s);
}

void	parsing(char **av, char ***splited)
{
	int		i;
	char	*s;

	s = parsing1(av);
	i = 0;
	*splited = ft_split(s, ' ');
	free(s);
	if (!splited || *splited == NULL || *splited[0] == NULL)
		(free_splited(*splited), write(2, "Error\n", 6), exit(1));
	if (!check_int(*splited) || !check_range(*splited)
		|| check_double(*splited) == 0)
		(free_splited(*splited), write(2, "Error\n", 6), exit(1));
}

void	index_stack_1(t_node **stack)
{
	t_node	*t1;
	t_node	*t2;
	int		j;

	t1 = (*stack);
	while (t1)
	{
		t2 = (*stack);
		j = 0;
		while (t2)
		{
			if (t1->content > t2->content)
				j++;
			t2 = t2->next;
		}
		t1->index = j;
		t1 = t1->next;
	}
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	main(int ac, char **av)
{
	char	**splited;
	t_node	*a;
	t_node	*b;

	splited = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	parsing(av, &splited);
	a = imp_lis(splited);
	if (check_sorted_stack(&a))
	{
		free_stack(&a);
		exit(0);
	}
	if (ft_lstsize(a) <= 3)
		(stack_3(&a), free_stack(&a), exit(1));
	index_stack_1(&a);
	if (ft_lstsize(a) == 4)
		(stack_4(&a, &b), free_stack(&a), exit(1));
	if (ft_lstsize(a) == 5)
		(stack_5(&a, &b), free_stack(&a), exit(1));
	algo_ch(&a, &b);
	from_b_to_a(&a, &b);
	free_stack(&a);
}
