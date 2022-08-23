/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_3_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:09:41 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <libft.h>

t_mtx3	ft_mtx3_mult_scalar(t_mtx3 m3, float scalar)
{
	m3.m11 *= scalar;
	m3.m12 *= scalar;
	m3.m13 *= scalar;
	m3.m21 *= scalar;
	m3.m22 *= scalar;
	m3.m23 *= scalar;
	m3.m31 *= scalar;
	m3.m32 *= scalar;
	m3.m33 *= scalar;
	return (m3);
}

t_vec2	ft_vec2_mult_mtx3(t_vec2 v2, t_mtx3 m3)
{
	t_vec2	temp;
	float	z;

	temp.x = v2.x * m3.m11 + v2.y * m3.m21 + m3.m31;
	temp.y = v2.x * m3.m12 + v2.y * m3.m22 + m3.m32;
	z = v2.x * m3.m13 + v2.y * m3.m23 + m3.m33;
	temp.x /= z;
	temp.y /= z;
	return (temp);
}

t_vec2	ft_mtx3_mult_vec2(t_mtx3 m3, t_vec2 v2)
{
	t_vec2	temp;
	float	z;

	temp.x = v2.x * m3.m11 + v2.y * m3.m12 + m3.m13;
	temp.y = v2.x * m3.m21 + v2.y * m3.m22 + m3.m23;
	z = v2.x * m3.m31 + v2.y * m3.m32 + m3.m33;
	temp.x /= z;
	temp.y /= z;
	return (temp);
}

t_mtx3	ft_mtx3_mult_mtx3(t_mtx3 m3_1, t_mtx3 m3_2)
{
	t_mtx3	new;

	new.m11 = m3_1.m11 * m3_2.m11 + m3_1.m12 * m3_2.m21 + m3_1.m13 * m3_2.m31;
	new.m12 = m3_1.m11 * m3_2.m12 + m3_1.m12 * m3_2.m22 + m3_1.m13 * m3_2.m32;
	new.m13 = m3_1.m11 * m3_2.m13 + m3_1.m12 * m3_2.m23 + m3_1.m13 * m3_2.m33;
	new.m21 = m3_1.m21 * m3_2.m11 + m3_1.m22 * m3_2.m21 + m3_1.m23 * m3_2.m31;
	new.m22 = m3_1.m21 * m3_2.m12 + m3_1.m22 * m3_2.m22 + m3_1.m23 * m3_2.m32;
	new.m23 = m3_1.m21 * m3_2.m13 + m3_1.m22 * m3_2.m23 + m3_1.m23 * m3_2.m33;
	new.m31 = m3_1.m31 * m3_2.m11 + m3_1.m32 * m3_2.m21 + m3_1.m33 * m3_2.m31;
	new.m32 = m3_1.m31 * m3_2.m12 + m3_1.m32 * m3_2.m22 + m3_1.m33 * m3_2.m32;
	new.m33 = m3_1.m31 * m3_2.m13 + m3_1.m32 * m3_2.m23 + m3_1.m33 * m3_2.m33;
	return (new);
}
