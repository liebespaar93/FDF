/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_ply_v3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 07:45:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:16:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_get_next_line.h>
#include <ft_polygon.h>
#include <ft_fdf.h>

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

void	ft_fdf_read_file_to_ply_v3_buff_while(t_vec3 *v3, \
	char *data, t_ply *ply, int *index)
{
	char	*line;
	int		len;

	line = data;
	len = ft_split_map_len(data, ' ');
	while (len--)
	{
		v3->z = ft_atoi_move(&line);
		v3->color = 0xFFFFFFFF;
		if (*line == ',' && line++)
			v3->color = ft_atoi_base(&line);
		ply->v3_buff[(*index)++] = *v3;
		v3->x++;
	}
	v3->y++;
	v3->x = 0;
}

void	ft_fdf_read_file_to_ply_v3_buff(t_ply *ply, t_read_line *read_line)
{
	t_vec3	v3;
	int		index;

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
		ft_fdf_read_file_to_ply_v3_buff_while(&v3, \
			read_line->data, ply, &index);
		read_line = read_line->next;
	}
}
