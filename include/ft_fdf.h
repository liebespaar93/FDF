/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:07:32 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/09 20:08:58 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_FDF_H
# define FT_FDF_H

#include <ft_get_next_line.h>
#include <ft_vector.h>
#include <ft_polygon.h>

/* fdf */
size_t	ft_read_file_size_v3(t_read_line *read_line);
t_ply	*ft_fdf_read_file_to_ply_v3_buff(t_ply *ply, t_read_line *read_line);
size_t	ft_read_file_size_prim(t_read_line *read_line);
void	ft_fdf_file_to_ply_prim_buff_while(t_ply *ply, \
	size_t *vec_index, size_t *index_ptr);
t_ply	*ft_fdf_read_file_to_ply_prim_buff(t_ply *ply, t_read_line *read_line);

/* fdf_ply */
t_ply	*ft_fdf_ply_max_v3(t_ply *ply);
// t_ply	*ft_polygon_new_cpy(t_ply *ply);
// t_ply	*ft_fdf_ply_color_v3_buff(t_ply *ply)


#endif