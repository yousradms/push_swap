/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydoumas <ydoumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:55:34 by ydoumas           #+#    #+#             */
/*   Updated: 2024/02/25 12:58:13 by ydoumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*c;

	i = 0;
	j = 0;
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	c = malloc(sizeof(char) * ((ft_strlen(s1)+ft_strlen(s2)) + 1));
	if (!c)
		return (NULL);
	while (s1[i])
		c[j++] = s1[i++];
	i = 0;
	while (s2[i])
		c[j++] = s2[i++];
	c[j] = '\0';
	return (c);
}
