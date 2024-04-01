/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:00:41 by ydoumas           #+#    #+#             */
/*   Updated: 2024/04/01 21:54:48 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
#include<stdbool.h>

// #define malloc(x) NULL
typedef struct s_node
{
	int content;
	int index;
	// int position;
	// int target_pos;
	// int cost_a;
	// int cost_b;
	struct s_node	*next;
}t_node;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
long		ft_atoi(const char *str);
int	ft_strcmp(char *s1, char *s2);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int content);
int	ft_lstsize(t_node *lst);
void parsing(int ac , char **av, char ***splited);
t_node *imp_lis(char **f);
void	sa(t_node **stack, int print);
void	sb(t_node **stack, int print);
void	ss(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a, int print);
void	rrb(t_node **stack_b, int print);
void	rrr(t_node **stack_a , t_node **stack_b);
void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);



#endif