/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_four_connect_axis_four.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:46:15 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:46:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_four	*ft_d_four_connect_axis1_four(t_d_four *d_standard, \
	t_d_four *d_next, t_d_axis axis4_1, t_d_axis axis4_2)
{
	t_d_four	d_temp;

	while (d_next)
	{
		d_temp = *d_next;
		ft_d_four_connect_four(d_standard, d_next, axis4_1.order[0]);
		*d_next = d_temp;
		if (axis4_2.order[0])
			ft_d_four_connect_four(d_next, d_standard, axis4_2.order[0]);
		d_standard = ft_d_four_addr(d_standard, axis4_1.order[1]);
		d_next = ft_d_four_addr(d_next, axis4_2.order[1]);
	}
	return (d_standard);
}
