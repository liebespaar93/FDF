/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axis_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:37:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 09:37:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

int	ft_axis_out(int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (c_option.s_bit.p_1 || c_option.s_bit.m_1)
		return (1);
	else if (c_option.s_bit.p_2 || c_option.s_bit.m_2)
		return (2);
	else if (c_option.s_bit.p_3 || c_option.s_bit.m_3)
		return (3);
	else if (c_option.s_bit.p_4 || c_option.s_bit.m_4)
		return (4);
	return (0);
}

int	ft_axis_opp(int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (c_option.s_bit.p_1 || c_option.s_bit.m_1)
		return (option ^ 3);
	else if (c_option.s_bit.p_2 || c_option.s_bit.m_2)
		return (option ^ 12);
	else if (c_option.s_bit.p_3 || c_option.s_bit.m_3)
		return (option ^ 48);
	else if (c_option.s_bit.p_4 || c_option.s_bit.m_4)
		return (option ^ 192);
	return (0);
}
