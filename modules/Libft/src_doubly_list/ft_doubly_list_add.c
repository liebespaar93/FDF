/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_list_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:54:56 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/15 10:46:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>

t_d_list	*ft_d_list_add_next(t_d_list *standard, t_d_list *next)
{
	if (!standard)
		return (next);
	if (standard->next)
		ft_d_list_connect_prev(standard->next, next);
	ft_d_list_connect_next(standard, next);
	return (next);
}

t_d_list	*ft_d_list_add_prev(t_d_list *standard, t_d_list *prev)
{
	if (!standard)
		return (prev);
	if (standard->prev)
		ft_d_list_connect_next(standard->next, prev);
	ft_d_list_connect_prev(standard, prev);
	return (prev);
}
