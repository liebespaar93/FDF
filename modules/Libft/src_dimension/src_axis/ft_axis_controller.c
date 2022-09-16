/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axis_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:37:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 09:37:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_axis	ft_axis_switch(t_d_axis axis, int order1, int order2)
{
	int	temp;

	temp = axis.order[order1];
	axis.order[order1] = axis.order[order2];
	axis.order[order2] = temp;
	return (axis);
}

t_d_axis	ft_axis_move(t_d_axis axis, int move)
{
	int	temp;
	int	i;

	while (move-- > 0)
	{
		i = 0;
		temp = axis.order[i];
		while (i < axis.dimension - 1)
		{
			axis.order[i] = axis.order[i + 1];
			i++;
		}
		axis.order[i] = temp;
	}
	return (axis);
}
