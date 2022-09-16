/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_two_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:05 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_two	*ft_d_two_addr(t_d_two *d_2, int option)
{
	t_d_option	c_option;

	c_option.option = option;
	if (!option)
		return (d_2);
	if (!d_2)
		return (NULL);
	if (c_option.s_bit.p_1 && ft_d_two_addr(d_2->connect1_p, option - 1))
		return (ft_d_two_addr(d_2->connect1_p, option - 1));
	if (c_option.s_bit.m_1 && ft_d_two_addr(d_2->connect1_m, option - 2))
		return (ft_d_two_addr(d_2->connect1_m, option - 2));
	if (c_option.s_bit.p_2 && ft_d_two_addr(d_2->connect2_p, option - 4))
		return (ft_d_two_addr(d_2->connect2_p, option - 4));
	if (c_option.s_bit.m_2 && ft_d_two_addr(d_2->connect2_m, option - 8))
		return (ft_d_two_addr(d_2->connect2_m, option - 8));
	return (NULL);
}
