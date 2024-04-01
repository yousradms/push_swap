/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:39:26 by ydoumas           #+#    #+#             */
/*   Updated: 2024/03/08 17:39:11 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	elem -> content = content;
	elem -> next = NULL;
	return (elem);
}
