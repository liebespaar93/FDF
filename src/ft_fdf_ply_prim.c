/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_ply_prim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 07:45:10 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 07:56:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_get_next_line.h>
#include <ft_polygon.h>
#include <libft.h>
#include <ft_fdf.h>

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

void	ft_fdf_read_file_to_ply_prim_buff_while(t_ply *ply, \
	size_t *vec_index, size_t *index_ptr)
{
	size_t	index;

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

void	ft_fdf_read_file_to_ply_prim_buff(t_ply *ply, t_read_line *read_line)
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
		vec_index[0] = ft_split_map_len(read_line->data, ' ');
		while (vec_index[3] < vec_index[0])
			ft_fdf_read_file_to_ply_prim_buff_while(ply, vec_index, &index);
		vec_index[2] += vec_index[0];
		vec_index[1] = vec_index[0];
		read_line = read_line->next;
	}
}
