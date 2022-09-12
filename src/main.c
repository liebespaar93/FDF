/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:07:51 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/12 08:08:07 by kyoulee          ###   ########.fr       */
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
#include <ft_printf.h>
#include <ft_color.h>
#include <ft_mlx_color.h>
#include <ft_fdf.h>


size_t	ft_split_map_len(char const *s, char c)
{
	size_t	split_len;
	int		flag;

	flag = 1;
	split_len = 0;
	while (*s != '\0' && *s != '\n')
	{
		if (*s != c)
		{
			if (flag)
				split_len++;
			flag = 0;
		}
		else
			flag = 1;
		s++;
	}
	return (split_len);
}



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
	if (ft_key_update(param->screan, param->keyboard) ||
		ft_mouse_update(param->screan, param->mouse))
	{
		ft_memset(param->back_buffer, 0, param->size_line * CANVAS_HEIGHT);
		ft_memcpy(param->ply->v3_buff, param->ply_origin->v3_buff, sizeof(t_vec3) * param->ply->size_v3);
		ft_draw_ply(param);
		ft_memcpy(param->buffer, param->back_buffer, \
			param->size_line * CANVAS_HEIGHT);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
			param->img_ptr, CANVAS_X, CANVAS_Y);
	}
	return (0);
}

t_ply	*ft_polygon_new_cpy(t_ply *ply)
{
	t_ply	*new;
	size_t	i;

	if (!ft_zeromalloc((void **)&new, sizeof(t_ply)) || \
		!ft_zeromalloc((void **)&new->v3_buff, sizeof(t_vec3) * ply->size_v3) || \
		!ft_zeromalloc((void **)&new->prim_buff, sizeof(t_prim) * ply->size_prim))
		return (ft_ply_free(&new));
	ft_memcpy(&new->max_v3, &ply->max_v3, sizeof(t_vec3));
	ft_memcpy(&new->min_v3, &ply->min_v3, sizeof(t_vec3));
	ft_memcpy(&new->size_v3, &ply->size_v3, sizeof(size_t));
	ft_memcpy(&new->size_prim, &ply->size_prim, sizeof(size_t));
	i = 0;
	while (i < ply->size_v3)
	{
		ft_memcpy(&new->v3_buff[i], &ply->v3_buff[i], sizeof(t_vec3));
		i++;
	}
	i = 0;
	while (i < ply->size_prim)
	{
		ft_memcpy(&new->prim_buff[i], &ply->prim_buff[i], sizeof(t_prim));
		i++;
	}
	return (new);
}


size_t	ft_map_len(t_read_line	*read_line)
{
	size_t		data_index;

	if (!read_line)
		return (0);
	data_index = 0;
	while (read_line)
	{
		data_index += ft_split_map_len(read_line->data, ' ');
		read_line = read_line->next;
	}
	return (data_index);
}

void	ft_fdf_map(t_ply *ply, t_read_line *read_line)
{
	t_vec3	v3;
	char	*line;
	int		index;
	int		len;

	if (!read_line || !ply)
		return ;
	ply->size_v3 = ft_map_len(read_line);
	ply->v3_buff = malloc(sizeof(t_vec3) * ply->size_v3);
	if (!ply->v3_buff)
		return ;
	ft_memset(&v3, 0, sizeof(t_vec3));
	index = 0;
	while (read_line)
	{
		line = read_line->data;
		len = ft_split_map_len(read_line->data, ' ');
		while (len--)
		{
			v3.z = ft_atoi_move(&line);
			v3.color = 0xFFFFFFFF;
			if (*line == ',' && line++)
				v3.color = ft_atoi_base(&line);
			ply->v3_buff[index++] = v3;
			v3.x++;
		}
		v3.y++;
		v3.x = 0;
		read_line = read_line->next;
	}
}

size_t	ft_map_len2(t_read_line *read_line)
{
	size_t		data_index;

	if (!read_line)
		return (0);
	data_index = 0;
	while (read_line)
	{
		data_index += ft_split_map_len(read_line->data, ' ');
		read_line = read_line->next;
	}
	return (data_index);
}

void	temp(t_ply *ply, size_t *vec_index, size_t *index_ptr)
{
	size_t index;

	index = *index_ptr;
	ply->prim_buff[index].p1 = vec_index[2] + vec_index[3];
	if (vec_index[3] + 1 < vec_index[0])
		ply->prim_buff[index].p2 = vec_index[2] + vec_index[3] + 1;
	if (vec_index[3] < vec_index[1])
		ply->prim_buff[index].p3 = vec_index[2] + vec_index[3] - vec_index[1];
	vec_index[3]++;
	index++;
	*index_ptr = index;
}

void	ft_fdf_map2(t_ply *ply, t_read_line *read_line)
{
	size_t		index;
	size_t		vec_index[4];

	if (!read_line || !ply)
		return ;
	ply->size_prim = ft_map_len2(read_line);
	ply->prim_buff = (t_prim *)malloc(sizeof(t_prim) * ply->size_prim);
	if (!ply->prim_buff)
		return ;
	ft_memset(ply->prim_buff, -1, sizeof(t_prim) * ply->size_prim);
	ft_memset(vec_index, 0, sizeof(size_t [4]));
	index = 0;
	while (read_line)
	{
		vec_index[3] = 0;
		vec_index[0] =  ft_split_map_len(read_line->data, ' ');
		while (vec_index[3] < vec_index[0])
			temp(ply, vec_index, &index);
		vec_index[2] += vec_index[0];
		vec_index[1] = vec_index[0];
		read_line = read_line->next;
	}
}

t_ply	*ft_fdf_ply_color_v3_buff(t_ply *ply)
{
	int		i;
	t_vec3	*v3_buff;

	v3_buff = ply->v3_buff;
	i = 0;
	while ((size_t)i++ < ply->size_v3)
	{
		if (v3_buff->color == -1)
			v3_buff->color = ft_color_maker(ply, v3_buff->z);
		v3_buff++;
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
	ft_fdf_map(param->ply, read_file->line_head);
	ft_fdf_map2(param->ply, read_file->line_head);
	//ft_fdf_read_file_to_ply_v3_buff(param->ply, read_file->line_head));
	//ft_fdf_read_file_to_ply_prim_buff(param->ply, read_file->line_head));
	ft_fdf_ply_max_v3(param->ply);
	ft_fdf_ply_color_v3_buff(param->ply);
	ft_polygon_transform(param->ply, ft_mtx4_translation(-param->ply->max_v3.x / 2, -param->ply->max_v3.y / 2, 0));
	ft_screan_set(param->screan, \
		ft_vector_2(10, 0), ft_vector_2(0, -10), param->screan->origin);
	ft_mlx_key_mouse_set(param);
	param->ply_origin = ft_polygon_new_cpy(param->ply);
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);

	mlx_loop(param->mlx_ptr);
	ft_param_free(&param);

	return (0);
}
