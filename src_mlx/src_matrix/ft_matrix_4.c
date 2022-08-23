/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 07:16:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:09:27 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <libft.h>

t_mtx4	ft_matrix_4(float *m1, float *m2, float *m3, float*m4)
{
	t_mtx4	new;

	new.m11 = m1[0];
	new.m12 = m1[1];
	new.m13 = m1[2];
	new.m14 = m1[3];
	new.m21 = m2[0];
	new.m22 = m2[1];
	new.m23 = m2[2];
	new.m24 = m2[3];
	new.m31 = m3[0];
	new.m32 = m3[1];
	new.m33 = m3[2];
	new.m34 = m3[3];
	new.m41 = m4[0];
	new.m42 = m4[1];
	new.m43 = m4[2];
	new.m44 = m4[3];
	return (new);
}

t_mtx4	ft_mtx4_identity(void)
{
	t_mtx4		new;

	new = ft_matrix_4(\
		(float [4]){1, 0, 0, 0}, \
		(float [4]){0, 1, 0, 0}, \
		(float [4]){0, 0, 1, 0}, \
		(float [4]){0, 0, 0, 1});
	return (new);
}

t_mtx4	ft_mtx4_translation(float x, float y, float z)
{
	t_mtx4	new;

	new = ft_matrix_4(\
		(float [4]){1, 0, 0, x}, \
		(float [4]){0, 1, 0, y}, \
		(float [4]){0, 0, 1, z}, \
		(float [4]){0, 0, 0, 1});
	return (new);
}

t_mtx4	ft_mtx4_projection(float d)
{
	t_mtx4	new;

	new = ft_matrix_4(\
		(float [4]){1, 0, 0, 0}, \
		(float [4]){0, 1, 0, 0}, \
		(float [4]){0, 0, 1, 0}, \
		(float [4]){0, 0, 1 / d, 1});
	return (new);
}
