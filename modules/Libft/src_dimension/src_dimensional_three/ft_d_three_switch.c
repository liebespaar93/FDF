/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_three_switch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:47:38 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:47:39 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_three	*ft_d_three_switch_zero(t_d_three *d_3, t_d_zero *d_0, int option)
{
	t_d_three	*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_three_new(ft_d_two_new(ft_d_one_new(d_0)));
	if (c_option.s_bit.p_1)
		ft_d_three_connect1_p(d_new, ft_d_three_addr(d_3, 1));
	if (c_option.s_bit.m_1)
		ft_d_three_connect1_m(d_new, ft_d_three_addr(d_3, 2));
	if (c_option.s_bit.p_2)
		ft_d_three_connect2_p(d_new, ft_d_three_addr(d_3, 4));
	if (c_option.s_bit.m_2)
		ft_d_three_connect2_m(d_new, ft_d_three_addr(d_3, 8));
	if (c_option.s_bit.p_3)
		ft_d_three_connect3_p(d_new, ft_d_three_addr(d_3, 16));
	if (c_option.s_bit.m_3)
		ft_d_three_connect3_m(d_new, ft_d_three_addr(d_3, 32));
	return (d_new);
}

t_d_three	*ft_d_three_switch_two(t_d_three *d_3, t_d_two *d_2, int option)
{
	t_d_three	*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_three_new(d_2);
	if (c_option.s_bit.p_1)
		ft_d_three_connect1_p(d_new, ft_d_three_addr(d_3, 1));
	if (c_option.s_bit.m_1)
		ft_d_three_connect1_m(d_new, ft_d_three_addr(d_3, 2));
	if (c_option.s_bit.p_2)
		ft_d_three_connect2_p(d_new, ft_d_three_addr(d_3, 4));
	if (c_option.s_bit.m_2)
		ft_d_three_connect2_m(d_new, ft_d_three_addr(d_3, 8));
	if (c_option.s_bit.p_3)
		ft_d_three_connect3_p(d_new, ft_d_three_addr(d_3, 16));
	if (c_option.s_bit.m_3)
		ft_d_three_connect3_m(d_new, ft_d_three_addr(d_3, 32));
	return (d_new);
}

t_d_three	*ft_d_three_switch_three(t_d_three *d_standard, t_d_three *d_next, \
	int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (c_option.s_bit.p_1)
		ft_d_three_connect1_p(d_next, ft_d_three_addr(d_standard, 1));
	else if (c_option.s_bit.m_1)
		ft_d_three_connect1_m(d_next, ft_d_three_addr(d_standard, 2));
	else if (c_option.s_bit.p_2)
		ft_d_three_connect2_p(d_next, ft_d_three_addr(d_standard, 4));
	else if (c_option.s_bit.m_2)
		ft_d_three_connect2_m(d_next, ft_d_three_addr(d_standard, 8));
	else if (c_option.s_bit.p_3)
		ft_d_three_connect3_p(d_next, ft_d_three_addr(d_standard, 16));
	else if (c_option.s_bit.m_3)
		ft_d_three_connect3_m(d_next, ft_d_three_addr(d_standard, 32));
	return (d_next);
}
