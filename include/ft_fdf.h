/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:07:32 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:32:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <ft_get_next_line.h>
# include <ft_vector.h>
# include <ft_polygon.h>

/* ft_fdf_ply_v3 */
size_t	ft_map_len(t_read_line	*read_line);
void	ft_fdf_read_file_to_ply_v3_buff(t_ply *ply, t_read_line *read_line);

/* ft_fdf_ply_prim */
void	ft_fdf_read_file_to_ply_prim_buff(t_ply *ply, t_read_line *read_line);
size_t	ft_map_len2(t_read_line *read_line);

/* ft_fdf_ply */
t_ply	*ft_polygon_new_cpy(t_ply *ply);
t_ply	*ft_fdf_ply_color_v3_buff(t_ply *ply);
size_t	ft_split_map_len(char const *s, char c);
t_ply	*ft_fdf_ply_max_v3(t_ply *ply);

#endif