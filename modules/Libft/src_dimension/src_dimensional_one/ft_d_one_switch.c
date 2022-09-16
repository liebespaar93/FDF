/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_one_switch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:49:16 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:49:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_one	*ft_d_one_switch_zero(t_d_one *d_1, t_d_zero *d_0, int option)
{
	t_d_one		*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_one_new(d_0);
	if (c_option.s_bit.p_1)
		ft_d_one_connect1_p(d_new, ft_d_one_addr(d_1, 1));
	if (c_option.s_bit.m_1)
		ft_d_one_connect1_m(d_new, ft_d_one_addr(d_1, 2));
	return (d_new);
}

t_d_one	*ft_d_one_switch_one(t_d_one *d_standard, t_d_one *d_new, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (c_option.s_bit.p_1)
		ft_d_one_connect1_p(d_new, ft_d_one_addr(d_new, 1));
	if (c_option.s_bit.m_1)
		ft_d_one_connect1_m(d_new, ft_d_one_addr(d_new, 2));
	return (d_new);
}
