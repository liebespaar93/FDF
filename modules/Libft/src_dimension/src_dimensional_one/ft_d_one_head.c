/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_one_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:49:04 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:49:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_one	*ft_d_one_head(t_d_one *d_1, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (!d_1)
		return (NULL);
	if (c_option.s_bit.p_1 || c_option.s_bit.m_1)
		d_1 = d_1->head1;
	return (d_1);
}
