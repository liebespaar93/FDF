/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_two_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:08 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_two	*ft_d_two_connect_zero(t_d_two *d_2, t_d_zero *d_0, int option)
{
	t_d_two		*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_two_new(ft_d_one_new(d_0));
	if (!d_new)
		return (NULL);
	else if (c_option.s_bit.p_1)
		ft_d_two_connect1_p(d_2, d_new);
	else if (c_option.s_bit.m_1)
		ft_d_two_connect1_m(d_2, d_new);
	else if (c_option.s_bit.p_2)
		ft_d_two_connect2_p(d_2, d_new);
	else if (c_option.s_bit.m_2)
		ft_d_two_connect2_m(d_2, d_new);
	return (d_new);
}

t_d_two	*ft_d_two_connect_one(t_d_two *d_2, t_d_one *d_1, int option)
{
	t_d_two		*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_two_new(d_1);
	if (!d_new)
		return (NULL);
	else if (c_option.s_bit.p_1)
		ft_d_two_connect1_p(d_2, d_new);
	else if (c_option.s_bit.m_1)
		ft_d_two_connect1_m(d_2, d_new);
	else if (c_option.s_bit.p_2)
		ft_d_two_connect2_p(d_2, d_new);
	else if (c_option.s_bit.m_2)
		ft_d_two_connect2_m(d_2, d_new);
	return (d_new);
}

t_d_two	*ft_d_two_connect_two(t_d_two *d_standard, t_d_two *d_next, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (c_option.s_bit.p_1)
		ft_d_two_connect1_p(d_standard, d_next);
	else if (c_option.s_bit.m_1)
		ft_d_two_connect1_m(d_standard, d_next);
	else if (c_option.s_bit.p_2)
		ft_d_two_connect2_p(d_standard, d_next);
	else if (c_option.s_bit.m_2)
		ft_d_two_connect2_m(d_standard, d_next);
	return (d_next);
}
