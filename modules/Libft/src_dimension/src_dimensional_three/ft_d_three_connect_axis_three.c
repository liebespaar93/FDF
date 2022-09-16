/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_three_connect_axis_three.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:47:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:47:18 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_three	*ft_d_three_connect_axis1_three(t_d_three *d_standard, \
	t_d_three *d_next, t_d_axis axis3_1, t_d_axis axis3_2)
{
	t_d_three	d_temp;

	while (d_next)
	{
		d_temp = *d_next;
		ft_d_three_connect_three(d_standard, d_next, axis3_1.order[1]);
		*d_next = d_temp;
		if (axis3_2.order[1])
			ft_d_three_connect_three(d_next, d_standard, axis3_2.order[1]);
		d_standard = ft_d_three_addr(d_standard, axis3_1.order[0]);
		d_next = ft_d_three_addr(d_next, axis3_2.order[0]);
	}
	return (d_standard);
}

t_d_three	*ft_d_three_connect_axis2_three(t_d_three *d_standard, \
	t_d_three *d_next, t_d_axis axis3_1, t_d_axis axis3_2)
{
	axis3_1.dimension = 3;
	axis3_2.dimension = 3;
	while (d_next)
	{
		ft_d_three_connect_axis1_three(d_standard, d_next,
			ft_axis_move(axis3_1, 1), ft_axis_move(axis3_2, 1));
		ft_d_three_connect_axis1_three(d_standard, d_next,
			ft_axis_move(axis3_1, 2), ft_axis_move(axis3_2, 2));
		d_standard = \
			ft_d_three_addr(d_standard, axis3_1.order[1] + axis3_1.order[2]);
		d_next = \
			ft_d_three_addr(d_standard, axis3_2.order[1] + axis3_2.order[2]);
	}
	return (d_next);
}
