/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_four_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:46:24 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:46:25 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_four	*ft_d_four_head(t_d_four *d_4, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (!d_4)
		return (NULL);
	if (c_option.s_bit.p_1 || c_option.s_bit.m_1)
		d_4 = d_4->head1;
	if (c_option.s_bit.p_2 || c_option.s_bit.m_2)
		d_4 = d_4->head2;
	if (c_option.s_bit.p_3 || c_option.s_bit.m_3)
		d_4 = d_4->head3;
	if (c_option.s_bit.p_4 || c_option.s_bit.m_4)
		d_4 = d_4->head4;
	return (d_4);
}
