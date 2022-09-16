/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_two_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:25 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:26 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_two	*ft_d_two_head(t_d_two *d_2, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (!d_2)
		return (NULL);
	if (c_option.s_bit.p_1 || c_option.s_bit.m_1)
		d_2 = d_2->head1;
	if (c_option.s_bit.p_2 || c_option.s_bit.m_2)
		d_2 = d_2->head2;
	return (d_2);
}
