/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:30:57 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 13:02:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_draw.h>
#include <ft_math.h>
#include <mlx.h>

void	ft_scanline_x(t_vec2 standard, t_vec2 next, t_param *param, int color)
{
	float	norm_x;
	float	norm_y;
	float	norm_titl;
	float	error;
	float	sign;

	norm_x = next.x - standard.x;
	norm_y = next.y - standard.y;
	norm_titl = ft_abs(norm_y / norm_x);
	error = 0;
	sign = ft_sign(norm_y);
	while (standard.x <= next.x)
	{
		if (0 <= standard.x && standard.x < CANVAS_X + CANVAS_WIDTH && \
			0 <= standard.y && standard.y < CANVAS_Y + CANVAS_HEIGHT)
			ft_backbuffer_put_pixel(standard.x, standard.y, color, param);
		error += norm_titl;
		if (error >= 0.5 && error--)
			standard.y += sign;
		standard.x++;
	}
}

void	ft_scanline_y(t_vec2 standard, t_vec2 next, t_param *param, int color)
{
	float	norm_x;
	float	norm_y;
	float	norm_titl;
	float	error;
	float	sign;

	norm_x = next.x - standard.x;
	norm_y = next.y - standard.y;
	norm_titl = ft_abs(norm_x / norm_y);
	error = 0;
	sign = ft_sign(norm_x);
	while (standard.y <= next.y)
	{
		if (0 <= standard.x && standard.x < CANVAS_X + CANVAS_WIDTH && \
			0 <= standard.y && standard.y < CANVAS_Y + CANVAS_HEIGHT)
			ft_backbuffer_put_pixel(standard.x, standard.y, color, param);
		error += norm_titl;
		if (error >= 0.5 && error--)
			standard.x += sign;
		standard.y++;
	}
}

void	ft_scanline(t_vec2 standard, t_vec2 next, t_param *param, int color)
{
	if (ft_abs(next.y - standard.y) < ft_abs(next.x - standard.x))
	{
		if (standard.x < next.x)
			ft_scanline_x(standard, next, param, color);
		else
			ft_scanline_x(next, standard, param, color);
	}
	else
	{
		if (standard.y < next.y)
			ft_scanline_y(standard, next, param, color);
		else
			ft_scanline_y(next, standard, param, color);
	}
}
