/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:29:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:28:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <ft_draw.h>

void	ft_draw_line(t_param *param, t_vec2 v2_1, t_vec2 v2_2)
{
	t_vec2	v1;
	t_vec2	v2;

	v1 = ft_basis2_transform(param->basis2, v2_1);
	v2 = ft_basis2_transform(param->basis2, v2_2);
	v1 = ft_screan_transform(param->screan, v1);
	v2 = ft_screan_transform(param->screan, v2);
	v1.color = v2_1.color;
	v2.color = v2_2.color;
	ft_scanline(v1, v2, param);
}

void	ft_draw_line_color(t_param *param, t_vec2 v2_1, t_vec2 v2_2)
{
	t_vec2	v1;
	t_vec2	v2;

	v1 = ft_basis2_transform(param->basis2, v2_1);
	v2 = ft_basis2_transform(param->basis2, v2_2);
	v1 = ft_screan_transform(param->screan, v1);
	v2 = ft_screan_transform(param->screan, v2);
	ft_scanline(v1, v2, param);
}

void	ft_draw_basis2_axis(t_param *param, int x, int y, int color)
{
	t_vec2	v2_1;
	t_vec2	v2_2;

	v2_1 = ft_vector_2(0, -x / 2);
	v2_1.color = color;
	v2_2 = ft_vector_2(0, x / 2);
	v2_2.color = color;
	ft_draw_line(param, v2_1, v2_2);
	v2_1 = ft_vector_2(-y / 2, 0);
	v2_1.color = color;
	v2_2 = ft_vector_2(y / 2, 0);
	v2_2.color = color;
	ft_draw_line(param, v2_1, v2_2);
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
		v1.color = color;
		v2.color = color;
		ft_draw_line(param, v1, v2);
		x_begin++;
	}
	while (y_begin <= y / 2)
	{
		v1 = ft_vector_2(x / 2, y_begin);
		v2 = ft_vector_2(-x / 2, y_begin);
		v1.color = color;
		v2.color = color;
		ft_draw_line(param, v1, v2);
		y_begin++;
	}
}
