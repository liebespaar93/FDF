/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screan.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:44:55 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/12 07:55:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCREAN_H
# define FT_SCREAN_H

# include <ft_vector.h>

typedef struct s_screan	t_screan;

typedef struct s_screan
{
	t_vec2	axis_1;
	t_vec2	axis_2;
	int		contour_line;
	t_vec2	origin;
	float	x_angle;
	float	y_angle;
}	t_screan;

t_screan	*ft_new_screan(t_vec2 v2_1, t_vec2 v2_2, t_vec2 v_origin);
t_screan	*ft_screan_init(void);
t_screan	*ft_screan_set(t_screan *screan, t_vec2 v2_1, t_vec2 v2_2, \
	t_vec2 v_origin);
t_vec2		ft_screan_transform(t_screan *screan, t_vec2 v2);
#endif
