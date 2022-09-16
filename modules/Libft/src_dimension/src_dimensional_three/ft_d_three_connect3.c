/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_three_connect3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:47:14 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:47:15 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_three	*ft_d_three_connect3_p(t_d_three *d_standard, t_d_three *d_new)
{
	if (!d_standard || !d_new)
		return (d_new);
	d_standard->connect3_p = d_new;
	d_new->connect3_m = d_standard;
	d_new->head3 = d_standard->head3;
	d_new->coordinate_1 = d_standard->coordinate_1;
	d_new->coordinate_2 = d_standard->coordinate_2;
	d_new->coordinate_3 = d_standard->coordinate_3 + 1;
	return (d_new);
}

t_d_three	*ft_d_three_connect3_m(t_d_three *d_standard, t_d_three *d_new)
{
	if (!d_standard || !d_new)
		return (d_new);
	d_standard->connect3_m = d_new;
	d_new->connect3_p = d_standard;
	d_new->head3 = d_standard->head3;
	d_new->coordinate_1 = d_standard->coordinate_1;
	d_new->coordinate_2 = d_standard->coordinate_2;
	d_new->coordinate_3 = d_standard->coordinate_3 - 1;
	return (d_new);
}
