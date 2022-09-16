/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_three_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:46:53 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:46:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_three	*ft_d_three_addr(t_d_three *d_3, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (!option)
		return (d_3);
	if (!d_3)
		return (NULL);
	if (c_option.s_bit.p_1 && ft_d_three_addr(d_3->connect1_p, option - 1))
		return (ft_d_three_addr(d_3->connect1_p, option - 1));
	if (c_option.s_bit.m_1 && ft_d_three_addr(d_3->connect1_m, option - 2))
		return (ft_d_three_addr(d_3->connect1_m, option - 2));
	if (c_option.s_bit.p_2 && ft_d_three_addr(d_3->connect2_p, option - 4))
		return (ft_d_three_addr(d_3->connect2_p, option - 4));
	if (c_option.s_bit.m_2 && ft_d_three_addr(d_3->connect2_m, option - 8))
		return (ft_d_three_addr(d_3->connect2_m, option - 8));
	if (c_option.s_bit.p_3 && ft_d_three_addr(d_3->connect3_p, option - 16))
		return (ft_d_three_addr(d_3->connect3_p, option - 16));
	if (c_option.s_bit.m_3 && ft_d_three_addr(d_3->connect3_m, option - 32))
		return (ft_d_three_addr(d_3->connect3_m, option - 32));
	return (NULL);
}
