/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:44:52 by ydoumas           #+#    #+#             */
/*   Updated: 2024/02/27 20:40:19 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
}
