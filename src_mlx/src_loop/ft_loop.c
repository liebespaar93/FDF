/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:11:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/12 07:44:43 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <libft.h>
#include <mlx.h>
#include <ft_mac_mouse.h>
#include <ft_mac_keyboard.h>

int	ft_key_update(t_screan *screan, t_keyboard *keyboard)
{
	t_vec2	v2;

	if (!keyboard->x && !keyboard->y && !keyboard->contour_line && !keyboard->zoom)
		return (0);
	v2 = ft_vector_2(keyboard->x, keyboard->y);
	screan->origin = ft_vec2_sum(screan->origin, v2);
	if (screan->axis_1.x > 0.1 || keyboard->zoom > 0)
	{
		screan->axis_1.x += keyboard->zoom * 0.1;
		screan->axis_2.y -= keyboard->zoom * 0.1;
	}
	screan->contour_line +=  keyboard->contour_line;
	keyboard->contour_line = 0;
	return (1);
}

int	ft_mouse_update(t_screan *screan, t_mouse *mouse)
{
	t_vec2	v2;

	if (!mouse->x_move && !mouse->y_move && !mouse->x_angle && !mouse->y_angle && !mouse->zoom)
		return (0);
	v2 = ft_vector_2(mouse->x_move, mouse->y_move);
	screan->origin = ft_vec2_sum(screan->origin, v2);
	if (screan->axis_1.x > 0.1 || mouse->zoom > 0)
	{
		screan->axis_1.x += mouse->zoom * 0.1;
		screan->axis_2.y -= mouse->zoom * 0.1;
	}
	screan->x_angle += mouse->x_angle;
	screan->y_angle += mouse->y_angle;
	mouse->x_angle = 0;
	mouse->y_angle = 0;
	mouse->zoom = 0;
	return (1);
}

void	ft_mlx_key_mouse_set(t_param *param)
{
	mlx_hook(param->win_ptr, 2, 0, ft_key_down, param->keyboard);
	mlx_key_hook(param->win_ptr, ft_key_up, param->keyboard);
	mlx_mouse_hook(param->win_ptr, ft_mouse_down, param->mouse);
	mlx_hook(param->win_ptr, 5, 0, ft_mouse_up, param->mouse);
	mlx_hook(param->win_ptr, 6, 0, ft_mouse_drag, param->mouse);
}
