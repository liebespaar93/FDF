/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:26:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <ft_math.h>

t_mtx3	ft_matrix_3(float *m1, float *m2, float *m3)
{
	t_mtx3	new;

	new.m11 = m1[0];
	new.m12 = m1[1];
	new.m13 = m1[2];
	new.m21 = m2[0];
	new.m22 = m2[1];
	new.m23 = m2[2];
	new.m31 = m3[0];
	new.m32 = m3[1];
	new.m33 = m3[2];
	return (new);
}

t_mtx3	ft_mtx3_identity(void)
{
	t_mtx3		new;

	new = ft_matrix_3(\
		(float [3]){1, 0, 0}, \
		(float [3]){0, 1, 0}, \
		(float [3]){0, 0, 1});
	return (new);
}

t_mtx3	ft_mtx3_translation(float x, float y)
{
	t_mtx3	new;

	new = ft_matrix_3(\
		(float [3]){1, 0, x}, \
		(float [3]){0, 1, y}, \
		(float [3]){0, 0, 1});
	return (new);
}

t_mtx3	ft_mtx3_shear(float x, float y)
{
	t_mtx3	new;

	new = ft_matrix_3(\
		(float [3]){1, y, 0}, \
		(float [3]){x, 1, 0}, \
		(float [3]){0, 0, 1});
	return (new);
}

t_mtx3	ft_mtx3_rotation(float angle)
{
	t_mtx3	new;
	double	sin;
	double	cos;

	sin = ft_sin(angle);
	cos = ft_cos(angle);
	new = ft_matrix_3(\
		(float [3]){cos, -sin, 0}, \
		(float [3]){sin, cos, 0}, \
		(float [3]){0, 0, 1});
	return (new);
}
