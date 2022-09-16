/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_three_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:47:24 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:47:28 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_three	*ft_d_three_head(t_d_three *d_3, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (!d_3)
		return (NULL);
	if (c_option.s_bit.p_1 || c_option.s_bit.m_1)
		d_3 = d_3->head1;
	if (c_option.s_bit.p_2 || c_option.s_bit.m_2)
		d_3 = d_3->head2;
	if (c_option.s_bit.p_3 || c_option.s_bit.m_3)
		d_3 = d_3->head3;
	return (d_3);
}
