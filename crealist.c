/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crealist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:42:22 by ydoumas           #+#    #+#             */
/*   Updated: 2024/03/29 18:04:29 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*imp_lis(char **f)
{
	t_node	*head;
	t_node	*new_node;
	int	i ;

	head = NULL;
	i = 0;
	while(f[i])
	{
		new_node = ft_lstnew(ft_atoi(f[i]));
		if(!new_node)
			return NULL;
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(f[i])));
		i++;
	}
	i = 0;
	while (f[i])
	{
		free(f[i]);
		i++;
	}
	free(f);
	return (head);
}