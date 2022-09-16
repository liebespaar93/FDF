/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_4_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 07:16:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:26:27 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <ft_math.h>

t_mtx4	ft_mtx4_rot_x(float angle)
{
	t_mtx4	new;
	double	sin;
	double	cos;

	sin = ft_sin(angle);
	cos = ft_cos(angle);
	new = ft_matrix_4(\
		(float [4]){1, 0, 0, 0}, \
		(float [4]){0, cos, -sin, 0}, \
		(float [4]){0, sin, cos, 0}, \
		(float [4]){0, 0, 0, 1});
	return (new);
}

t_mtx4	ft_mtx4_rot_y(float angle)
{
	t_mtx4	new;
	double	sin;
	double	cos;

	sin = ft_sin(angle);
	cos = ft_cos(angle);
	new = ft_matrix_4(\
		(float [4]){cos, 0, sin, 0}, \
		(float [4]){0, 1, 0, 0}, \
		(float [4]){-sin, 0, cos, 0}, \
		(float [4]){0, 0, 0, 1});
	return (new);
}

t_mtx4	ft_mtx4_rot_z(float angle)
{
	t_mtx4	new;
	double	sin;
	double	cos;

	sin = ft_sin(angle);
	cos = ft_cos(angle);
	new = ft_matrix_4(\
		(float [4]){cos, -sin, 0, 0}, \
		(float [4]){sin, cos, 0, 0}, \
		(float [4]){0, 0, 1, 0}, \
		(float [4]){0, 0, 0, 1});
	return (new);
}
