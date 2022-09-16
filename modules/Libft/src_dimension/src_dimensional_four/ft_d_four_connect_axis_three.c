/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_four_connect_axis_three.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:46:20 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:46:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_four	*ft_d_four_connect_axis1_three(t_d_four *d_4, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3)
{
	t_d_four	*d_new;
	t_d_four	*d_temp1;
	t_d_four	*d_temp2;
	t_d_four	*d_temp3;

	if (!d_3)
		return (NULL);
	d_new = d_4;
	d_temp1 = ft_d_four_addr(d_4, ft_axis_opp(axis4.order[1]) + axis4.order[0]);
	d_temp2 = ft_d_four_addr(d_4, ft_axis_opp(axis4.order[2]) + axis4.order[0]);
	d_temp3 = ft_d_four_addr(d_4, ft_axis_opp(axis4.order[3]) + axis4.order[0]);
	while (d_3)
	{
		d_new = ft_d_four_connect_three(d_new, d_3, axis4.order[0]);
		if (d_temp1 && ft_d_four_connect_four(d_temp1, d_new, axis4.order[1]))
			d_temp1 = ft_d_four_addr(d_temp1, axis4.order[0]);
		if (d_temp2 && ft_d_four_connect_four(d_temp2, d_new, axis4.order[2]))
			d_temp2 = ft_d_four_addr(d_temp2, axis4.order[0]);
		if (d_temp3 && ft_d_four_connect_four(d_temp3, d_new, axis4.order[3]))
			d_temp3 = ft_d_four_addr(d_temp3, axis4.order[0]);
		d_3 = ft_d_three_addr(d_3, axis3.order[0]);
	}
	return (d_new);
}

t_d_four	*ft_d_four_connect_axis2_three(t_d_four *d_4, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3)
{
	t_d_four	*d_next;
	t_d_four	*d_temp3;
	t_d_four	*d_temp4;

	d_temp3 = ft_d_four_addr(d_4, \
		ft_axis_opp(axis4.order[2]) + axis4.order[0] + axis4.order[1]);
	d_temp4 = ft_d_four_addr(d_4, \
		ft_axis_opp(axis4.order[3]) + axis4.order[0] + axis4.order[1]);
	axis4.dimension = 2;
	axis3.dimension = 2;
	while (d_3)
	{
		ft_d_four_connect_axis2_1_three_utils(d_4, d_3, axis4, axis3);
		d_3 = ft_d_three_addr(d_3, axis3.order[0] + axis3.order[1]);
		d_next = ft_d_four_new(d_3);
		if (!d_next)
			return (d_4);
		ft_d_four_connect_axis2_2_three_utils(d_next, d_4, axis4, axis3);
		if (d_temp3 && ft_d_four_connect_four(d_temp3, d_next, axis4.order[2]))
			d_temp3 = ft_d_four_addr(d_temp3, axis4.order[0] + axis4.order[1]);
		if (d_temp4 && ft_d_four_connect_four(d_temp4, d_next, axis4.order[3]))
			d_temp4 = ft_d_four_addr(d_temp4, axis4.order[0] + axis4.order[1]);
		d_4 = d_next;
	}
	return (NULL);
}

t_d_four	*ft_d_four_connect_axis3_three(t_d_four *d_4, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3)
{
	t_d_four	*d_next;
	t_d_four	*d_temp;

	axis4.dimension = 3;
	while (d_3)
	{
		ft_d_four_connect_axis2_three(d_4, d_3, axis4, axis3);
		d_temp = ft_d_four_new(ft_d_three_addr(d_3, axis3.order[2]));
		ft_d_four_connect_axis3_1_three_utils(d_4, d_temp, axis4, axis3);
		ft_d_four_connect_axis2_three(d_temp, ft_d_three_addr(d_3, \
			axis3.order[2]), ft_axis_move(axis4, 1), ft_axis_move(axis3, 1));
		d_temp = ft_d_four_new(\
			ft_d_three_addr(d_3, axis3.order[0] + axis3.order[2]));
		ft_d_four_connect_axis3_2_three_utils(d_4, d_temp, axis4, axis3);
		ft_d_four_connect_axis2_three(d_temp, \
			ft_d_three_addr(d_3, axis3.order[0] + axis3.order[2]), \
			ft_axis_move(axis4, 2), ft_axis_move(axis3, 2));
		d_3 = ft_d_three_addr(d_3, \
			axis3.order[0] + axis3.order[1] + axis3.order[2]);
		d_next = ft_d_four_new(d_3);
		if (!d_next)
			return (d_4);
		d_4 = ft_d_four_connect_axis3_3_three_utils(d_4, d_next, axis4, axis3);
	}
	return (NULL);
}

t_d_four	*ft_d_four_connect_axis4_three(t_d_four *d_4, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3)
{
	t_d_four	*d_new;
	t_d_four	*d_next;

	if (!d_3)
		return (NULL);
	d_new = ft_d_four_connect_three(d_4, d_3, axis4.order[0]);
	ft_d_four_connect_axis3_three(d_new, d_3, ft_axis_move(axis4, 1), axis3);
	return (d_new);
}
