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

void	ft_d_four_connect_axis2_1_three_utils(t_d_four *d_new, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3)
{
	ft_d_four_connect_axis1_three(d_new, \
		ft_d_three_addr(d_3, axis3.order[0]), \
		axis4, axis3);
	ft_d_four_connect_axis1_three(d_new, \
		ft_d_three_addr(d_3, axis3.order[1]), \
		ft_axis_move(axis4, 1), ft_axis_move(axis3, 1));
}

void	ft_d_four_connect_axis2_2_three_utils(t_d_four *d_next, t_d_four *d_4, \
	t_d_axis axis4, t_d_axis axis3)
{
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[0]), d_next, axis4.order[1]);
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[1]), d_next, axis4.order[0]);
}

void	ft_d_four_connect_axis3_1_three_utils(t_d_four *d_4, t_d_four *d_temp, \
	t_d_axis axis4, t_d_axis axis3)
{
	t_d_four	*d_temp4;

	d_temp4 = ft_d_four_addr(d_4, ft_axis_opp(axis4.order[3]));
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[2] + ft_axis_opp(axis4.order[0])), \
		d_temp, axis4.order[0]);
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[2] + ft_axis_opp(axis4.order[1])), \
		d_temp, axis4.order[1]);
	ft_d_four_connect_four(d_4, d_temp, axis4.order[2]);
	ft_d_four_connect_four(ft_d_four_addr(d_temp4, axis4.order[2]), \
		d_temp, axis4.order[3]);
}

void	ft_d_four_connect_axis3_2_three_utils(t_d_four *d_4, t_d_four *d_temp, \
	t_d_axis axis4, t_d_axis axis3)
{
	t_d_four	*d_temp4;

	d_temp4 = ft_d_four_addr(d_4, ft_axis_opp(axis4.order[3]));
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[2]), d_temp, axis4.order[0]);
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, \
			axis4.order[0] + axis4.order[2] + ft_axis_opp(axis4.order[1])), \
		d_temp, axis4.order[1]);
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[0]), d_temp, axis4.order[2]);
	ft_d_four_connect_four(\
		ft_d_four_addr(d_temp4, axis4.order[0] + axis4.order[2]), \
		d_temp, axis4.order[3]);
}

t_d_four	*ft_d_four_connect_axis3_3_three_utils(t_d_four *d_4, \
	t_d_four *d_next, t_d_axis axis4, t_d_axis axis3)
{
	t_d_four	*d_temp4;

	d_temp4 = ft_d_four_addr(d_4, ft_axis_opp(axis4.order[3]));
	d_temp4 = ft_d_four_addr(d_temp4, \
		axis4.order[0] + axis4.order[1] + axis4.order[2]);
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[1] + axis4.order[2]), \
		d_next, axis4.order[0]);
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[2] + axis4.order[0]), \
		d_next, axis4.order[1]);
	ft_d_four_connect_four(\
		ft_d_four_addr(d_4, axis4.order[0] + axis4.order[1]), \
		d_next, axis4.order[2]);
	ft_d_four_connect_four(d_temp4, d_next, axis4.order[3]);
	return (d_next);
}
