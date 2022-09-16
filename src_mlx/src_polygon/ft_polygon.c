/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polygon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:32:17 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:25:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_polygon.h>
#include <libft.h>

t_ply	*ft_ply_free(t_ply **ply_ptr)
{
	t_ply	*ply;

	ply = *ply_ptr;
	if (ply)
	{
		if (ply->prim_buff)
			free(ply->prim_buff);
		if (ply->v3_buff)
			free(ply->v3_buff);
		free(ply);
	}
	*ply_ptr = NULL;
	return (*ply_ptr);
}

t_ply	*ft_polygon_init(void)
{
	t_ply	*new;

	if (!ft_zeromalloc((void **)&new, sizeof(t_ply)))
		return (ft_ply_free(&new));
	return (new);
}

t_ply	*ft_ply_set_primbuffer(t_ply *ply, t_prim *buff, int index)
{
	if (!buff)
		return (ft_ply_free(&ply));
	ply->prim_buff = buff;
	ply->size_prim = index;
	return (ply);
}

t_ply	*ft_ply_set_vbuffer(t_ply *ply, t_vec3 *buff, int index)
{
	if (!buff)
		return (ft_ply_free(&ply));
	ply->v3_buff = buff;
	ply->size_v3 = index;
	return (ply);
}

t_ply	*ft_ply_set(t_ply *ply, int ****coord_3D)
{
	t_prim	*prim_buff;
	t_vec3	*v3_buff;
	void	**coord_temp;

	if (!ply)
		return (NULL);
	prim_buff = NULL;
	v3_buff = NULL;
	coord_temp = NULL;
	if (coord_3D && *coord_3D && **coord_3D && ***coord_3D)
		coord_temp = (void *[3]){*coord_3D, **coord_3D, ***coord_3D};
	while (coord_temp[0])
	{
		while (coord_temp[1])
		{
			while (coord_temp[2])
				coord_temp[2] = (int *)coord_temp[2] + 1;
			coord_temp[1] = (int **)coord_temp[1] + 1;
		}
		coord_temp[0] = (int ***)coord_temp[0] + 1;
	}
	ft_ply_set_primbuffer(ply, prim_buff, 12);
	ft_ply_set_vbuffer(ply, v3_buff, 8);
	return (ply);
}
