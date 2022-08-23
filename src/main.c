#include <libft.h>
#include <ft_get_next_line.h>
#include <fcntl.h>
#include <ft_param.h>
#include <mlx.h>
#include <ft_loop.h>
#include <ft_polygon.h>
#include <ft_math.h>
#include <ft_draw.h>
#include <ft_printf.h>

void	ft_draw_prim(t_param *param, t_ply *ply, t_prim prim)
{
	if (prim.p1 != (size_t)-1 && prim.p2 != (size_t)-1)
		ft_draw_line(param, \
		ft_vector_2(ply->v3_buff[prim.p1].x, ply->v3_buff[prim.p1].y), \
		ft_vector_2(ply->v3_buff[prim.p2].x, ply->v3_buff[prim.p2].y), \
		0x00FFCC66);
	if (prim.p2 != (size_t)-1 && prim.p3 != (size_t)-1)
		ft_draw_line(param, \
		ft_vector_2(ply->v3_buff[prim.p2].x, ply->v3_buff[prim.p2].y), \
		ft_vector_2(ply->v3_buff[prim.p3].x, ply->v3_buff[prim.p3].y), \
		0x00FFCC66);
	if (0 && prim.p1 != (size_t)-1 && prim.p3 != (size_t)-1)
		ft_draw_line(param, \
		ft_vector_2(ply->v3_buff[prim.p3].x, ply->v3_buff[prim.p3].y), \
		ft_vector_2(ply->v3_buff[prim.p1].x, ply->v3_buff[prim.p1].y), \
		0x00FFCC66);
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
	param->keyboard->contour_line = 0;
	m4_rot_x = ft_mtx4_rot_x(C_PI * param->mouse->y_angle / 180);
	m4_rot_y = ft_mtx4_rot_y(C_PI * param->mouse->x_angle / 180);
	param->mouse->y_angle = 0;
	param->mouse->x_angle = 0;
	m4_tranform = ft_mtx4_mult_mtx4(m4_rot_y, m4_rot_x);
	ply = ft_polygon_transform(ply, m4_tranform);
	while ((size_t)i < ply->size_prim)
		ft_draw_prim(param, ply, ply->prim_buff[i++]);
}

int	ft_loop_event(t_param *param)
{
	ft_key_update(param->screan, param->keyboard);
	ft_mouse_update(param->screan, param->mouse);
	ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
	ft_draw_ply(param);
	ft_memcpy(param->buffer, param->back_buffer, \
		param->size_line * CANVAS_HEIGHT);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
		param->img_ptr, CANVAS_X, CANVAS_Y);
	return (0);
}


#include <stdio.h>

size_t	ft_read_file_size_v3(t_read_file *read_file)
{
	t_read_line	*read_line;
	size_t		data_index;

	data_index = 0;
	read_line = read_file->line_head;
	while (read_line)
	{
		data_index += ft_atoi_len(read_line->data);
		read_line = read_line->next;
	}
	return (data_index);
}

t_ply	*ft_fdf_read_file_to_ply_v3_buff(t_ply *ply, t_read_file *read_file)
{
	t_read_line	*read_line;
	int			*data;
	size_t		data_len;
	float		coord[3];
	int			i;

	if (!read_file || !read_file->line_head || !ply)
		return (NULL);
	ft_bzero(&coord, sizeof(float[3]));
	read_line = read_file->line_head;
	ply->size_v3 = ft_read_file_size_v3(read_file);
	if (!ft_zeromalloc((void **)&ply->v3_buff, sizeof(t_vec3) * ply->size_v3))
		return (NULL);
	i = 0;
	while (read_line)
	{
		data_len = ft_atoi_arr(&data, read_line->data);
		while (coord[2] < data_len)
			ply->v3_buff[i++] = ft_vector_3(coord[0]++, coord[1], data[(int)coord[2]++]);
		coord[0] = 0;
		coord[1] += 1;
		coord[2] = 0;
		read_line = read_line->next;
		free(data);
	}
	read_line = read_file->line_head;
	return (ply);
}

size_t	ft_read_file_size_prim(t_read_file *read_file)
{
	t_read_line	*read_line;
	size_t		data_index;

	if (!read_file)
		return (0);
	read_line = read_file->line_head;
	data_index = 0;
	while (read_line)
	{
		data_index += ft_atoi_len(read_line->data) - 1;
		read_line = read_line->next;
	}
	return (data_index);
}

t_ply	*ft_fdf_read_file_to_ply_prim_buff(t_ply *ply, t_read_file *read_file)
{
	t_read_line	*read_line;
	size_t		index;
	size_t		vec_index_now;
	size_t		vec_index_prev;
	size_t		vec_index_sum;
	size_t		coord;

	if (!read_file || !read_file->line_head || !ply)
		return (NULL);
	ply->size_prim = ft_read_file_size_prim(read_file);
	if (!ft_zeromalloc((void **)&ply->prim_buff, sizeof(t_prim) * ply->size_prim))
		return (NULL);
	ft_memset(ply->prim_buff, -1, sizeof(t_prim) * ply->size_prim);
	index = 0;
	read_line = read_file->line_head;
	vec_index_sum = 0;
	vec_index_prev = 0;
	while (read_line)
	{
		coord = 0;
		vec_index_now = ft_atoi_len(read_line->data) - 1;
		while (coord < vec_index_now)
		{
			ply->prim_buff[index].p1 = vec_index_sum + coord;
			ply->prim_buff[index].p2 = vec_index_sum + coord + 1;
			if (coord < vec_index_prev)
				ply->prim_buff[index].p3 = vec_index_sum + coord - vec_index_prev;
			coord++;
			index++;
		}
		vec_index_sum += vec_index_now + 1;
		vec_index_prev = vec_index_now;
		read_line = read_line->next;
	}
	return (ply);
}

t_ply	*ft_fdf_ply_max_v3(t_ply *ply)
{
	t_vec3	*v3_buff;
	size_t	index;

	if (!ply)
		return (NULL);
	v3_buff = ply->v3_buff;
	index = 0;
	while (index < ply->size_v3)
	{
		ply->max_v3.x = ft_float_max(ply->max_v3.x, v3_buff[index].x);
		ply->max_v3.y = ft_float_max(ply->max_v3.y, v3_buff[index].y);
		ply->max_v3.z = ft_float_max(ply->max_v3.z, v3_buff[index].z);
		index++;
	}
	return (ply);
}
int	main(int ar, char * av[])
{
	int			fd;
	t_read_file *read_file;
	t_param		*param;

	fd = 0;
	if (ar == 2)
		fd = ft_open(av[1], O_RDONLY);
	read_file = ft_read_file(fd);
	close(fd);
	param = ft_param_init();
	ft_fdf_read_file_to_ply_v3_buff(param->ply, read_file);
	ft_fdf_read_file_to_ply_prim_buff(param->ply, read_file);
	ft_fdf_ply_max_v3(param->ply);
	ft_polygon_transform(param->ply, ft_mtx4_translation(-param->ply->max_v3.x / 2, -param->ply->max_v3.y / 2, 0));
	ft_screan_set(param->screan, \
		ft_vector_2(10, 0), ft_vector_2(0, -10), param->screan->origin);
	ft_mlx_key_mouse_set(param);
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);

	mlx_loop(param->mlx_ptr);
	ft_param_free(&param);

	return (0);
}
