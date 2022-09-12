/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:30:57 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:27:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_draw.h>
#include <ft_math.h>
#include <mlx.h>
#include <ft_mlx_color.h>

void	ft_scanline_x(t_vec2 standard, t_vec2 next, t_param *param)
{
	float	norm_titl;
	float	error;
	float	sign;
	t_vec2	current;
	int		mix_color;

	norm_titl = ft_abs((next.y - standard.y) / (next.x - standard.x));
	error = 0;
	sign = ft_sign(next.y - standard.y);
	current = standard;
	while (current.x <= next.x)
	{
		mix_color = ft_get_color(ft_percent(standard.x, next.x, current.x), \
			standard.color, next.color);
		if (0 <= current.x && current.x < CANVAS_X + CANVAS_WIDTH && \
			0 <= current.y && current.y < CANVAS_Y + CANVAS_HEIGHT)
			ft_backbuffer_put_pixel(current.x, current.y, mix_color, param);
		error += norm_titl;
		if (error >= 0.5 && error--)
			current.y += sign;
		current.x++;
	}
}

void	ft_scanline_y(t_vec2 standard, t_vec2 next, t_param *param)
{
	float	norm_titl;
	float	error;
	float	sign;
	t_vec3	current;
	int		mix_color;

	norm_titl = ft_abs((next.x - standard.x) / (next.y - standard.y));
	error = 0;
	sign = ft_sign(next.x - standard.x);
	current.x = standard.x;
	current.y = standard.y;
	current.z = 0;
	while (current.y <= next.y)
	{
		mix_color = ft_get_color(ft_percent(standard.y, next.y, current.y), \
			standard.color, next.color);
		if (0 <= current.x && current.x < CANVAS_X + CANVAS_WIDTH && \
			0 <= current.y && current.y < CANVAS_Y + CANVAS_HEIGHT)
			ft_backbuffer_put_pixel(current.x, current.y, mix_color, param);
		error += norm_titl;
		if (error >= 0.5 && error--)
			current.x += sign;
		current.y++;
	}
}

void	ft_scanline(t_vec2 standard, t_vec2 next, t_param *param)
{
	if (ft_abs(next.y - standard.y) < ft_abs(next.x - standard.x))
	{
		if (standard.x < next.x)
			ft_scanline_x(standard, next, param);
		else
			ft_scanline_x(next, standard, param);
	}
	else
	{
		if (standard.y < next.y)
			ft_scanline_y(standard, next, param);
		else
			ft_scanline_y(next, standard, param);
	}
}
