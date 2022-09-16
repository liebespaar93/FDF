/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_list_head_add.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:28:29 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/15 10:42:04 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>

t_d_list_header	*ft_d_list_header_add_head(t_d_list_header *standard, \
	t_d_list *prev)
{
	if (!prev)
		return (standard);
	if (!standard)
		return (ft_d_list_header_init(prev));
	ft_d_list_add_prev(standard->head, prev);
	standard->head = prev;
	if (!standard->tail)
		standard->tail = prev;
	return (standard);
}

t_d_list_header	*ft_d_list_header_add_tail(t_d_list_header *standard, \
	t_d_list *next)
{
	if (!next)
		return (standard);
	if (!standard)
		return (ft_d_list_header_init(next));
	ft_d_list_add_next(standard->tail, next);
	standard->tail = next;
	if (!standard->head)
		standard->head = next;
	return (standard);
}
