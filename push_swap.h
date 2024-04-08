/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:00:41 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/08 06:57:54 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}	t_node;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
long	ft_atoi(const char *str);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int content);
int		ft_lstsize(t_node *lst);
t_node	*imp_lis(char **f);
void	sa(t_node **stack, int print);
void	sb(t_node **stack, int print);
void	ss(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a, int print);
void	rrb(t_node **stack_b, int print);
void	rrr(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
t_node	*get_bef_max(t_node **stack, t_node *max);
t_node	*get_max(t_node **stack);
void	free_splited(char **numbs);
void	algo_ch(t_node **stack_a, t_node **stack_b);
void	from_b_to_a(t_node **stack_a, t_node **stack_b);
int		check_empty(char *d);
int		check_int(char **d);
int		check_range(char **d);
int		check_double(char **d);
int		ft_abs(int i);
void	stack_3(t_node **stack_a);
void	stack_4(t_node **stack_a, t_node **stack_b);
void	stack_5(t_node **stack_a, t_node **stack_b);
void	free_stack(t_node **stack);
int		check_sorted_stack(t_node **stack_a);

#endif