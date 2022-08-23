/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polygon_transform.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:32:17 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/23 11:05:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_polygon.h>

t_ply	*ft_polygon_transform(t_ply *ply, t_mtx4 m4)
{
	int		i;
	t_vec3	*v3_buff;

	v3_buff = ply->v3_buff;
	i = 0;
	while ((size_t)i++ < ply->size_v3)
	{
		*v3_buff = ft_mtx4_mult_vec3(m4, *v3_buff);
		v3_buff++;
	}
	return (ply);
}
