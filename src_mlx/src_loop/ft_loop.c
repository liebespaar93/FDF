/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:11:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/23 11:10:23 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <libft.h>
#include <mlx.h>
#include <ft_mac_mouse.h>
#include <ft_mac_keyboard.h>

void	ft_key_update(t_screan *screan, t_keyboard *keyboard)
{
	t_vec2	v2;

	v2 = ft_vector_2(keyboard->x, keyboard->y);
	screan->origin = ft_vec2_sum(screan->origin, v2);
	screan->axis_1.x += keyboard->zoom;
	screan->axis_2.y -= keyboard->zoom;
}

void	ft_mouse_update(t_screan *screan, t_mouse *mouse)
{
	t_vec2	v2;

	v2 = ft_vector_2(mouse->x_move, mouse->y_move);
	screan->origin = ft_vec2_sum(screan->origin, v2);
	screan->axis_1.x += mouse->zoom;
	screan->axis_2.y -= mouse->zoom;
	mouse->zoom = 0;
}

void	ft_mlx_key_mouse_set(t_param *param)
{
	mlx_hook(param->win_ptr, 2, 0, ft_key_down, param->keyboard);
	mlx_key_hook(param->win_ptr, ft_key_up, param->keyboard);
	mlx_mouse_hook(param->win_ptr, ft_mouse_down, param->mouse);
	mlx_hook(param->win_ptr, 5, 0, ft_mouse_up, param->mouse);
	mlx_hook(param->win_ptr, 6, 0, ft_mouse_drag, param->mouse);
}
