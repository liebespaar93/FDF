/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:29:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 13:35:24 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <ft_draw.h>

void	ft_draw_line(t_param *param, t_vec2 v2_1, t_vec2 v2_2, int color)
{
	t_vec2	v1;
	t_vec2	v2;

	v1 = ft_basis2_transform(param->basis2, v2_1);
	v2 = ft_basis2_transform(param->basis2, v2_2);
	v1 = ft_screan_transform(param->screan, v1);
	v2 = ft_screan_transform(param->screan, v2);
	ft_scanline(v1, v2, param, color);
}

void	ft_draw_basis2_axis(t_param *param, int x, int y, int color)
{
	ft_draw_line(param, ft_vector_2(0, -x / 2), ft_vector_2(0, x / 2), color);
	ft_draw_line(param, ft_vector_2(-y / 2, 0), ft_vector_2(y / 2, 0), color);
}

void	ft_draw_basis2_grid(t_param *param, int x, int y, int color)
{
	t_vec2	v1;
	t_vec2	v2;
	int		x_begin;
	int		y_begin;

	x_begin = -x / 2;
	y_begin = -y / 2;
	while (x_begin <= x / 2)
	{
		v1 = ft_vector_2(x_begin, y / 2);
		v2 = ft_vector_2(x_begin, -y / 2);
		ft_draw_line(param, v1, v2, color);
		x_begin++;
	}
	while (y_begin <= y / 2)
	{
		v1 = ft_vector_2(x / 2, y_begin);
		v2 = ft_vector_2(-x / 2, y_begin);
		ft_draw_line(param, v1, v2, color);
		y_begin++;
	}
}
