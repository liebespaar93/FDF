/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_one_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:53 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_one	*ft_d_one_connect_zero(t_d_one *d_1, t_d_zero *d_0, int option)
{
	t_d_one		*d_new;
	t_d_option	c_option;

	c_option.option = option;
	d_new = ft_d_one_new(d_0);
	if (!d_new)
		return (NULL);
	else if (c_option.s_bit.p_1)
		ft_d_one_connect1_p(d_1, d_new);
	else if (c_option.s_bit.m_1)
		ft_d_one_connect1_m(d_1, d_new);
	return (d_new);
}

t_d_one	*ft_d_one_connect_one(t_d_one *d_standard, t_d_one *d_next, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (c_option.s_bit.p_1)
		ft_d_one_connect1_p(d_standard, d_next);
	else if (c_option.s_bit.m_1)
		ft_d_one_connect1_m(d_standard, d_next);
	return (d_next);
}
