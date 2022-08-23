/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:27:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <ft_math.h>

t_mtx2	ft_matrix_2(float m11, float m12, float m21, float m22)
{
	t_mtx2	new;

	new.m11 = m11;
	new.m12 = m12;
	new.m21 = m21;
	new.m22 = m22;
	return (new);
}

t_mtx2	ft_mtx2_identity(void)
{
	t_mtx2		new;

	new = ft_matrix_2(1, 0, 0, 1);
	return (new);
}

t_mtx2	ft_mtx2_shear(float x, float y)
{
	t_mtx2	new;

	new.m11 = 1;
	new.m12 = y;
	new.m21 = x;
	new.m22 = 1;
	return (new);
}

t_mtx2	ft_mtx2_rotation(float angle)
{
	t_mtx2		new;
	double		sin;
	double		cos;

	sin = ft_sin(angle);
	cos = ft_cos(angle);
	new = ft_matrix_2(cos, -sin, sin, cos);
	return (new);
}
