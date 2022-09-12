/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:05:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/09 20:03:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_get_next_line.h>
#include <libft.h>
#include <ft_vector.h>
#include <ft_polygon.h>
#include <ft_math.h>

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
	ft_bzero(&coord, sizeof(float [3]));
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
		data_index += ft_atoi_len(read_line->data);
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
		vec_index_now = ft_atoi_len(read_line->data);
		while (coord < vec_index_now)
		{
			ply->prim_buff[index].p1 = vec_index_sum + coord;
			if (coord + 1 < vec_index_now)
				ply->prim_buff[index].p2 = vec_index_sum + coord + 1;
			if (coord < vec_index_prev)
				ply->prim_buff[index].p3 = vec_index_sum + coord - vec_index_prev;
			coord++;
			index++;
		}
		vec_index_sum += vec_index_now;
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
		ply->min_v3.x = ft_float_min(ply->max_v3.x, v3_buff[index].x);
		ply->min_v3.y = ft_float_min(ply->max_v3.y, v3_buff[index].y);
		ply->min_v3.z = ft_float_min(ply->max_v3.z, v3_buff[index].z);
		index++;
	}
	return (ply);
}
