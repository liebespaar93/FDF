/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:42:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/12 08:09:03 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_screan.h>
#include <stdlib.h>

t_screan	*ft_new_screan(t_vec2 v2_1, t_vec2 v2_2, t_vec2 v_origin)
{
	t_screan	*new;

	new = (t_screan *)malloc(sizeof(t_screan));
	if (!new)
		return (NULL);
	new->axis_1 = v2_1;
	new->axis_2 = v2_2;
	new->contour_line = 0;
	new->origin = v_origin;
	return (new);
}

t_screan	*ft_screan_init(void)
{
	t_vec2	v2_1;
	t_vec2	v2_2;
	t_vec2	v2_origin;

	v2_1 = ft_vector_2(1, 0);
	v2_2 = ft_vector_2(0, -1);
	v2_origin = ft_vector_2(0, 0);
	return (ft_new_screan(v2_1, v2_2, v2_origin));
}

t_screan	*ft_screan_set(t_screan *screan, t_vec2 v2_1, t_vec2 v2_2, \
	t_vec2 v_origin)
{
	screan->axis_1 = v2_1;
	screan->axis_2 = v2_2;
	screan->origin = v_origin;
	screan->contour_line = 1;
	return (screan);
}

t_vec2	ft_screan_transform(t_screan *screan, t_vec2 v2)
{
	v2 = ft_vec2_sum(\
		ft_vec2_mult(screan->axis_1, v2.x), \
		ft_vec2_mult(screan->axis_2, v2.y) \
		);
	return (ft_vec2_sum(v2, screan->origin));
}
