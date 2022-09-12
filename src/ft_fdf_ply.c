/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_ply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:27:56 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/09 20:09:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_polygon.h>
#include <libft.h>
#include <ft_math.h>

// t_ply	*ft_fdf_ply_max_v3(t_ply *ply)
// {
// 	t_vec3	*v3_buff;
// 	size_t	index;

// 	if (!ply)
// 		return (NULL);
// 	v3_buff = ply->v3_buff;
// 	index = 0;
// 	while (index < ply->size_v3)
// 	{
// 		ply->max_v3.x = ft_float_max(ply->max_v3.x, v3_buff[index].x);
// 		ply->max_v3.y = ft_float_max(ply->max_v3.y, v3_buff[index].y);
// 		ply->max_v3.z = ft_float_max(ply->max_v3.z, v3_buff[index].z);
// 		ply->min_v3.x = ft_float_min(ply->max_v3.x, v3_buff[index].x);
// 		ply->min_v3.y = ft_float_min(ply->max_v3.y, v3_buff[index].y);
// 		ply->min_v3.z = ft_float_min(ply->max_v3.z, v3_buff[index].z);
// 		index++;
// 	}
// 	return (ply);
// }

// t_ply	*ft_polygon_new_cpy(t_ply *ply)
// {
// 	t_ply	*new;
// 	int		i;

// 	if (!ft_zeromalloc((void **)&new, sizeof(t_ply)) || \
// 		!ft_zeromalloc((void **)&new->v3_buff, \
// 		sizeof(t_vec3) * ply->size_v3) || \
// 		!ft_zeromalloc((void **)&new->prim_buff, \
// 		sizeof(t_prim) * ply->size_prim))
// 		return (ft_ply_free(&new));
// 	ft_memcpy(&new->max_v3, &ply->max_v3, sizeof(t_vec3));
// 	ft_memcpy(&new->min_v3, &ply->min_v3, sizeof(t_vec3));
// 	ft_memcpy(&new->size_v3, &ply->size_v3, sizeof(size_t));
// 	ft_memcpy(&new->size_prim, &ply->size_prim, sizeof(size_t));
// 	i = -1;
// 	while ((size_t)++i < ply->size_v3)
// 		ft_memcpy(&new->v3_buff[i], &ply->v3_buff[i], sizeof(t_vec3));
// 	i = -1;
// 	while ((size_t)++i < ply->size_prim)
// 		ft_memcpy(&new->prim_buff[i], &ply->prim_buff[i], sizeof(t_prim));
// 	return (new);
// }

// t_ply	*ft_fdf_ply_color_v3_buff(t_ply *ply)
// {
// 	int		i;
// 	t_vec3	*v3_buff;

// 	v3_buff = ply->v3_buff;
// 	i = 0;
// 	while ((size_t)i++ < ply->size_v3)
// 	{
// 		if (v3_buff->color == -1)
// 			v3_buff->color = ft_color_maker(ply, v3_buff->z);
// 		v3_buff++;
// 	}
// 	return (ply);
// }
