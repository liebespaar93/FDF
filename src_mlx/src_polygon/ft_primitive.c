/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:48:51 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:10:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_polygon.h>
#include <libft.h>

t_prim	ft_primitive(int p1, int p2, int p3)
{
	t_prim	new;

	new.p1 = p1;
	new.p2 = p2;
	new.p3 = p3;
	return (new);
}

/*
* 90도가 만들어지는 시계 반대방향 회전
* +x +z, +z -x, -x -z, -z +x
* +y -x, -x -y, -y +x, +x +y
* +z +y, +y -z, -z -y, -y +z
* ft_primitive(0, +x, +y)
* ft_primitive(0, +x, +z)
* ft_primitive(0, +y, -x)
* ft_primitive(0, +y, -z)
* ft_primitive(0, +z, -x)
* ft_primitive(0, +z, +y)
* ft_primitive(0, -x, -y)
* ft_primitive(0, -x, -z)
* ft_primitive(0, -y, +x)
* ft_primitive(0, -y, +z)
* ft_primitive(0, -z, +x)
* ft_primitive(0, -z, -y)
*/
t_prim	*ft_prim_cube(t_prim **prim_buff_ptr, int *cube)
{
	t_prim	*prim_buff;

	if (prim_buff_ptr)
		prim_buff = *prim_buff_ptr;
	else if (!ft_zeromalloc((void **)&prim_buff, sizeof(t_prim) * 12))
		return (NULL);
	prim_buff[0] = ft_primitive(cube[0], cube[1], cube[2]);
	prim_buff[1] = ft_primitive(cube[0], cube[1], cube[4]);
	prim_buff[2] = ft_primitive(cube[0], cube[4], cube[2]);
	prim_buff[3] = ft_primitive(cube[3], cube[7], cube[2]);
	prim_buff[4] = ft_primitive(cube[3], cube[2], cube[1]);
	prim_buff[5] = ft_primitive(cube[3], cube[1], cube[7]);
	prim_buff[6] = ft_primitive(cube[5], cube[4], cube[1]);
	prim_buff[7] = ft_primitive(cube[5], cube[1], cube[7]);
	prim_buff[8] = ft_primitive(cube[5], cube[7], cube[4]);
	prim_buff[9] = ft_primitive(cube[6], cube[2], cube[4]);
	prim_buff[10] = ft_primitive(cube[6], cube[2], cube[7]);
	prim_buff[11] = ft_primitive(cube[6], cube[4], cube[7]);
	return (prim_buff);
}
