/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_four_switch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:46:32 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:46:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_four	*ft_d_four_switch_zero(t_d_four *d_4, t_d_zero *d_0, int option)
{
	t_d_four	*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_four_new(ft_d_three_new(ft_d_two_new(ft_d_one_new(d_0))));
	if (c_option.s_bit.p_1)
		ft_d_four_connect1_p(d_new, ft_d_four_addr(d_new, 1));
	if (c_option.s_bit.m_1)
		ft_d_four_connect1_m(d_new, ft_d_four_addr(d_new, 2));
	if (c_option.s_bit.p_2)
		ft_d_four_connect2_p(d_new, ft_d_four_addr(d_new, 4));
	if (c_option.s_bit.m_2)
		ft_d_four_connect2_m(d_new, ft_d_four_addr(d_new, 8));
	if (c_option.s_bit.p_3)
		ft_d_four_connect3_p(d_new, ft_d_four_addr(d_new, 16));
	if (c_option.s_bit.m_3)
		ft_d_four_connect3_m(d_new, ft_d_four_addr(d_new, 32));
	if (c_option.s_bit.p_4)
		ft_d_four_connect4_p(d_new, ft_d_four_addr(d_new, 64));
	if (c_option.s_bit.m_4)
		ft_d_four_connect4_m(d_new, ft_d_four_addr(d_new, 128));
	return (d_new);
}

t_d_four	*ft_d_four_switch_three(t_d_four *d_4, t_d_three *d_3, int option)
{
	t_d_four	*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_four_new(d_3);
	if (c_option.s_bit.p_1)
		ft_d_four_connect1_p(d_new, ft_d_four_addr(d_new, 1));
	if (c_option.s_bit.m_1)
		ft_d_four_connect1_m(d_new, ft_d_four_addr(d_new, 2));
	if (c_option.s_bit.p_2)
		ft_d_four_connect2_p(d_new, ft_d_four_addr(d_new, 4));
	if (c_option.s_bit.m_2)
		ft_d_four_connect2_m(d_new, ft_d_four_addr(d_new, 8));
	if (c_option.s_bit.p_3)
		ft_d_four_connect3_p(d_new, ft_d_four_addr(d_new, 16));
	if (c_option.s_bit.m_3)
		ft_d_four_connect3_m(d_new, ft_d_four_addr(d_new, 32));
	if (c_option.s_bit.p_4)
		ft_d_four_connect4_p(d_new, ft_d_four_addr(d_new, 64));
	if (c_option.s_bit.m_4)
		ft_d_four_connect4_m(d_new, ft_d_four_addr(d_new, 128));
	return (d_new);
}

t_d_four	*ft_d_four_switch_four(t_d_four *d_standard, \
	t_d_four *d_next, int option)
{
	t_d_four	*d_new;
	t_d_option	c_option;

	c_option.option = option;
	if (c_option.s_bit.p_1)
		ft_d_four_connect1_p(d_next, ft_d_four_addr(d_standard, 1));
	else if (c_option.s_bit.m_1)
		ft_d_four_connect1_m(d_next, ft_d_four_addr(d_standard, 2));
	else if (c_option.s_bit.p_2)
		ft_d_four_connect2_p(d_next, ft_d_four_addr(d_standard, 4));
	else if (c_option.s_bit.m_2)
		ft_d_four_connect2_m(d_next, ft_d_four_addr(d_standard, 8));
	else if (c_option.s_bit.p_3)
		ft_d_four_connect3_p(d_next, ft_d_four_addr(d_standard, 16));
	else if (c_option.s_bit.m_3)
		ft_d_four_connect3_m(d_next, ft_d_four_addr(d_standard, 32));
	else if (c_option.s_bit.p_4)
		ft_d_four_connect4_p(d_next, ft_d_four_addr(d_standard, 64));
	else if (c_option.s_bit.m_4)
		ft_d_four_connect4_m(d_next, ft_d_four_addr(d_standard, 128));
	return (d_new);
}
