/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:46:47 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/08 03:00:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <libft.h>
#include <stdlib.h>
#include <mlx.h>

t_param	*ft_param_free(t_param **param_ptr)
{
	t_param	*param;

	param = *param_ptr;
	if (param)
	{
		if (param->mlx_ptr)
			free(param->mlx_ptr);
		if (param->win_ptr)
			free(param->win_ptr);
		if (param->screan)
			free(param->screan);
		if (param->basis2)
			free(param->basis2);
		if (param->ply)
			ft_ply_free(&param->ply);
		if (param->ply_origin)
			ft_ply_free(&param->ply_origin);
		if (param->keyboard)
			free(param->keyboard);
		if (param->mouse)
			free(param->mouse);
		free(param);
	}
	*param_ptr = NULL;
	return (*param_ptr);
}

t_param	*ft_param_init(void)
{
	t_param	*param;

	if (!ft_zeromalloc((void **)&param, sizeof(t_param)))
		return (NULL);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
		"FDF by kyoulee");
	param->img_ptr = mlx_new_image(param->mlx_ptr, CANVAS_WIDTH, CANVAS_HEIGHT);
	param->buffer = mlx_get_data_addr(param->img_ptr, &param->bits_per_pixel, \
		&param->size_line, &param->endian);
	if (!ft_zeromalloc((void **)&param->back_buffer, \
		param->size_line * CANVAS_HEIGHT) || \
		!ft_ptrcpy((void **)&param->basis2, ft_basis2_init()) || \
		!ft_ptrcpy((void **)&param->screan, ft_screan_init()) || \
		!ft_ptrcpy((void **)&param->ply, ft_polygon_init()) || \
		!ft_zeromalloc((void **)&param->keyboard, sizeof(t_keyboard)) || \
		!ft_zeromalloc((void **)&param->mouse, sizeof(t_mouse)))
		return (ft_param_free(&param));
	param->screan->origin.x = CANVAS_X + CANVAS_WIDTH / 2;
	param->screan->origin.y = CANVAS_Y + CANVAS_HEIGHT / 2;
	return (param);
}
