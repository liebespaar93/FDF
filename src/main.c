/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:07:51 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:39:02 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_get_next_line.h>
#include <fcntl.h>
#include <ft_param.h>
#include <mlx.h>
#include <ft_loop.h>
#include <ft_polygon.h>
#include <ft_math.h>
#include <ft_draw.h>
#include <ft_color.h>
#include <ft_mlx_color.h>
#include <ft_fdf.h>

void	ft_draw_prim(t_param *param, t_ply *ply, t_prim prim)
{
	if (prim.p1 != (size_t)-1 && prim.p2 != (size_t)-1)
		ft_draw_line(param, \
		ft_vec_3to2(ply->v3_buff[prim.p1]), \
		ft_vec_3to2(ply->v3_buff[prim.p2]));
	if (0 && prim.p2 != (size_t)-1 && prim.p3 != (size_t)-1)
		ft_draw_line(param, \
		ft_vec_3to2(ply->v3_buff[prim.p2]), \
		ft_vec_3to2(ply->v3_buff[prim.p3]));
	if (prim.p1 != (size_t)-1 && prim.p3 != (size_t)-1)
		ft_draw_line(param, \
		ft_vec_3to2(ply->v3_buff[prim.p3]), \
		ft_vec_3to2(ply->v3_buff[prim.p1]));
}

void	ft_draw_ply(t_param *param)
{
	t_ply	*ply;
	t_mtx4	m4_rot_x;
	t_mtx4	m4_rot_y;
	t_mtx4	m4_tranform;
	int		i;

	ply = param->ply;
	i = 0;
	m4_rot_x = ft_mtx4_rot_x(C_PI * param->screan->y_angle / 180);
	m4_rot_y = ft_mtx4_rot_y(C_PI * param->screan->x_angle / 180);
	m4_tranform = ft_mtx4_identity();
	m4_tranform.m33 = param->screan->contour_line;
	ply = ft_polygon_transform(ply, m4_tranform);
	m4_tranform = ft_mtx4_mult_mtx4(m4_rot_y, m4_rot_x);
	ply = ft_polygon_transform(ply, m4_tranform);
	while ((size_t)i < ply->size_prim)
	{
		ft_draw_prim(param, ply, ply->prim_buff[i]);
		i++;
	}
}

int	ft_loop_event(t_param *param)
{
	if (ft_key_update(param->screan, param->keyboard) || \
		ft_mouse_update(param->screan, param->mouse))
	{
		ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
		ft_memcpy(param->ply->v3_buff, \
			param->ply_origin->v3_buff, sizeof(t_vec3) * param->ply->size_v3);
		ft_draw_ply(param);
		ft_memcpy(param->buffer, param->back_buffer, \
			param->size_line * CANVAS_HEIGHT);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
			param->img_ptr, CANVAS_X, CANVAS_Y);
	}
	return (0);
}

void	ft_fdf_start(t_param *param)
{
	ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
	ft_memcpy(param->ply->v3_buff, \
		param->ply_origin->v3_buff, sizeof(t_vec3) * param->ply->size_v3);
	ft_draw_ply(param);
	ft_memcpy(param->buffer, param->back_buffer, \
		param->size_line * CANVAS_HEIGHT);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
		param->img_ptr, CANVAS_X, CANVAS_Y);
}

int	main(int ar, char *av[])
{
	int			fd;
	t_read_file	*read_file;
	t_param		*param;

	fd = 0;
	if (ar == 2)
		fd = ft_open(av[1], O_RDONLY);
	read_file = ft_read_file(fd);
	close(fd);
	param = ft_param_init();
	ft_fdf_read_file_to_ply_v3_buff(param->ply, read_file->line_head);
	ft_fdf_read_file_to_ply_prim_buff(param->ply, read_file->line_head);
	ft_fdf_ply_max_v3(param->ply);
	ft_fdf_ply_color_v3_buff(param->ply);
	ft_polygon_transform(param->ply, ft_mtx4_translation(\
		-param->ply->max_v3.x / 2, -param->ply->max_v3.y / 2, 0));
	ft_screan_set(param->screan, \
		ft_vector_2(10, 0), ft_vector_2(0, -10), param->screan->origin);
	param->ply_origin = ft_polygon_new_cpy(param->ply);
	ft_fdf_start(param);
	ft_mlx_key_mouse_set(param);
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);
	mlx_loop(param->mlx_ptr);
	ft_param_free(&param);
	return (0);
}
