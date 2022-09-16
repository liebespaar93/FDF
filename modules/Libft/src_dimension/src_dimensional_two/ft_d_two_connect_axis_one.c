/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_two_connect_axis_one.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_two	*ft_d_two_connect_axis1_one(t_d_two *d_2, t_d_one *d_1, \
	t_d_axis axis2, t_d_axis axis1)
{
	t_d_two	*d_new;
	t_d_two	*d_temp1;

	if (!d_1)
		return (NULL);
	d_new = d_2;
	d_temp1 = ft_d_two_addr(d_2, ft_axis_opp(axis2.order[1]) + axis2.order[0]);
	while (d_1)
	{
		d_new = ft_d_two_connect_one(d_new, d_1, axis2.order[0]);
		if (d_temp1 && ft_d_two_connect_two(d_temp1, d_new, axis2.order[1]))
			d_temp1 = ft_d_two_addr(d_temp1, axis2.order[0]);
		d_1 = ft_d_one_addr(d_1, axis1.order[0]);
	}
	return (d_new);
}

t_d_two	*ft_d_two_connect_axis2_one(t_d_two *d_2, t_d_one *d_1, \
	t_d_axis axis2, t_d_axis axis1)
{
	t_d_two	*d_new;

	if (!d_1)
		return (NULL);
	d_new = ft_d_two_connect_one(d_2, d_1, axis2.order[0]);
	d_1 = ft_d_one_addr(d_1, axis1.order[0]);
	d_new = ft_d_two_connect_axis1_one(d_new, d_1, \
		ft_axis_move(axis2, 1), axis1);
	return (d_new);
}
