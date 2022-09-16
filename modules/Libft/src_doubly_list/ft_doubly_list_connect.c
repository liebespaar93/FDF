/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_list_connect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:51:27 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/11 06:57:23 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>

void	ft_d_list_connect_next(t_d_list *standard, t_d_list *next)
{
	if (standard)
		standard->next = next;
	if (next)
		next->prev = standard;
}

void	ft_d_list_connect_prev(t_d_list *standard, t_d_list *next)
{
	if (standard)
		standard->prev = next;
	if (next)
		next->next = standard;
}
