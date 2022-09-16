/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_one_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:47 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_one	*ft_d_one_addr(t_d_one *d_1, int option)
{
	t_d_option	c_option;

	if (!option)
		return (d_1);
	c_option.option = option;
	if (!d_1)
		return (NULL);
	if (c_option.s_bit.p_1 && ft_d_one_addr(d_1->connect1_p, option - 1))
		return (ft_d_one_addr(d_1->connect1_p, option - 1));
	if (c_option.s_bit.m_1 && ft_d_one_addr(d_1->connect1_m, option - 2))
		return (ft_d_one_addr(d_1->connect1_m, option - 2));
	return (NULL);
}
