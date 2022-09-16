/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_three_connect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:46:57 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:46:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_three	*ft_d_three_connect_zero(t_d_three *d_3, t_d_zero *d_0, int option)
{
	t_d_three	*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_three_new(ft_d_two_new(ft_d_one_new(d_0)));
	if (!d_new)
		return (NULL);
	else if (c_option.s_bit.p_1)
		ft_d_three_connect1_p(d_3, d_new);
	else if (c_option.s_bit.m_1)
		ft_d_three_connect1_m(d_3, d_new);
	else if (c_option.s_bit.p_2)
		ft_d_three_connect2_p(d_3, d_new);
	else if (c_option.s_bit.m_2)
		ft_d_three_connect2_m(d_3, d_new);
	else if (c_option.s_bit.p_3)
		ft_d_three_connect3_p(d_3, d_new);
	else if (c_option.s_bit.m_3)
		ft_d_three_connect3_m(d_3, d_new);
	return (d_new);
}

t_d_three	*ft_d_three_connect_two(t_d_three *d_3, t_d_two *d_2, int option)
{
	t_d_three	*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_three_new(d_2);
	if (!d_new)
		return (NULL);
	else if (c_option.s_bit.p_1)
		ft_d_three_connect1_p(d_3, d_new);
	else if (c_option.s_bit.m_1)
		ft_d_three_connect1_m(d_3, d_new);
	else if (c_option.s_bit.p_2)
		ft_d_three_connect2_p(d_3, d_new);
	else if (c_option.s_bit.m_2)
		ft_d_three_connect2_m(d_3, d_new);
	else if (c_option.s_bit.p_3)
		ft_d_three_connect3_p(d_3, d_new);
	else if (c_option.s_bit.m_3)
		ft_d_three_connect3_m(d_3, d_new);
	return (d_new);
}

t_d_three	*ft_d_three_connect_three(t_d_three *d_standard, t_d_three *d_next, \
	int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (c_option.s_bit.p_1)
		ft_d_three_connect1_p(d_standard, d_next);
	else if (c_option.s_bit.m_1)
		ft_d_three_connect1_m(d_standard, d_next);
	else if (c_option.s_bit.p_2)
		ft_d_three_connect2_p(d_standard, d_next);
	else if (c_option.s_bit.m_2)
		ft_d_three_connect2_m(d_standard, d_next);
	else if (c_option.s_bit.p_3)
		ft_d_three_connect3_p(d_standard, d_next);
	else if (c_option.s_bit.m_3)
		ft_d_three_connect3_m(d_standard, d_next);
	return (d_next);
}
