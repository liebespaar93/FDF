/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_three_connect_axis_two.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:47:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:47:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_three	*ft_d_three_connect_axis1_two(t_d_three *d_3, t_d_two *d_2, \
	t_d_axis axis3, t_d_axis axis2)
{
	t_d_three	*d_new;
	t_d_three	*d_temp1;
	t_d_three	*d_temp2;

	if (!d_2)
		return (NULL);
	d_new = d_3;
	d_temp1 = \
		ft_d_three_addr(d_3, ft_axis_opp(axis3.order[1]) + axis3.order[0]);
	d_temp2 = \
		ft_d_three_addr(d_3, ft_axis_opp(axis3.order[2]) + axis3.order[0]);
	while (d_2)
	{
		d_new = ft_d_three_connect_two(d_new, d_2, axis3.order[0]);
		if (d_temp1 && ft_d_three_connect_three(d_temp1, d_new, axis3.order[1]))
			d_temp1 = ft_d_three_addr(d_temp1, axis3.order[0]);
		if (d_temp2 && ft_d_three_connect_three(d_temp2, d_new, axis3.order[2]))
			d_temp2 = ft_d_three_addr(d_temp2, axis3.order[0]);
		d_2 = ft_d_two_addr(d_2, axis2.order[0]);
	}
	return (d_new);
}

t_d_three	*ft_d_three_connect_axis2_two(t_d_three *d_3, t_d_two *d_2, \
	t_d_axis axis3, t_d_axis axis2)
{
	t_d_three	*d_next;
	t_d_three	*d_temp3;

	d_temp3 = ft_d_three_addr(d_3, ft_axis_opp(axis3.order[2]));
	axis3.dimension = 2;
	while (d_2)
	{
		ft_d_three_connect_axis1_two(d_3, ft_d_two_addr(d_2, axis2.order[0]),
			ft_axis_move(axis3, 0), ft_axis_move(axis2, 0));
		ft_d_three_connect_axis1_two(d_3, ft_d_two_addr(d_2, axis2.order[1]),
			ft_axis_move(axis3, 1), ft_axis_move(axis2, 1));
		d_2 = ft_d_two_addr(d_2, axis2.order[0] + axis2.order[1]);
		d_temp3 = ft_d_three_addr(d_temp3, axis3.order[0] + axis3.order[1]);
		d_next = ft_d_three_new(d_2);
		if (!d_next)
			return (d_3);
		ft_d_three_connect_three(ft_d_three_addr(d_3, axis3.order[0]),
			d_next, axis3.order[1]);
		ft_d_three_connect_three(ft_d_three_addr(d_3, axis3.order[1]),
			d_next, axis3.order[0]);
		ft_d_three_connect_three(d_temp3, d_next, axis3.order[2]);
		d_3 = d_next;
	}
	return (NULL);
}

t_d_three	*ft_d_three_connect_axis3_two(t_d_three *d_3, t_d_two *d_2, \
	t_d_axis axis3, t_d_axis axis2)
{
	t_d_three	*d_new;
	t_d_three	*d_next;

	if (!d_2)
		return (NULL);
	d_new = ft_d_three_connect_two(d_3, d_2, axis3.order[0]);
	ft_d_three_connect_axis2_two(d_new, d_2, ft_axis_move(axis3, 1), axis2);
	return (d_new);
}
