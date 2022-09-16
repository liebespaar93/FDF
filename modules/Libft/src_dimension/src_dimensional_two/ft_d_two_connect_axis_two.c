/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_two_connect_axis_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:22 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:23 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_two	*ft_d_two_connect_axis1_two(t_d_two *d_standard, t_d_two *d_next, \
	t_d_axis axis2_1, t_d_axis axis2_2)
{
	t_d_two	d_temp1;

	while (d_next)
	{
		d_temp1 = *d_next;
		ft_d_two_connect_two(d_standard, d_next, axis2_1.order[0]);
		*d_next = d_temp1;
		if (axis2_2.order[0])
			ft_d_two_connect_two(d_next, d_standard, axis2_2.order[0]);
		d_standard = ft_d_two_addr(d_standard, axis2_1.order[1]);
		d_next = ft_d_two_addr(d_next, axis2_2.order[1]);
	}
	return (d_standard);
}
