/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axis_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:37:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 09:37:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_axis	ft_axis_init(int option, int dimension)
{
	t_d_axis	axis;
	int			i;
	int			num;

	ft_memset(&axis, 0, sizeof(t_d_axis));
	if (dimension > 4)
		dimension = 4;
	axis.dimension = dimension;
	axis.axis.option = option & ft_dimension(dimension);
	i = 0;
	num = 3;
	while (++i < dimension)
		num *= 4;
	while (i)
	{
		axis.order[dimension - i] = num & option;
		num /= 4;
		i--;
	}
	return (axis);
}

t_d_axis	ft_axis_order(t_d_axis axis, int *order)
{
	int	i;

	i = 0;
	while (i < axis.dimension && order)
		axis.order[i] = ft_axis(*order++) & axis.axis.option;
	return (axis);
}

int	ft_dimension(int dimension)
{
	if (dimension == 1)
		dimension = 3;
	else if (dimension == 2)
		dimension = 15;
	else if (dimension == 3)
		dimension = 63;
	else if (dimension == 4)
		dimension = 255;
	return (dimension);
}

int	ft_axis(int axis)
{
	if (axis == 1)
		return (3);
	if (axis == 2)
		return (12);
	if (axis == 3)
		return (48);
	if (axis == 4)
		return (192);
	return (0);
}
