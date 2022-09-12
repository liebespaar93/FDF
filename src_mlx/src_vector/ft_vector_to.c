/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:34:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/07 01:50:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

t_vec2	ft_vec_3to2(t_vec3 v3)
{
	t_vec2	v2;
	
	v2.x = v3.x;
	v2.y = v3.y;
	v2.color = v3.color;
	return (v2);
}