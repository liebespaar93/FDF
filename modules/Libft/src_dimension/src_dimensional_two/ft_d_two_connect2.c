/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_two_connect2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:15 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:16 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_two	*ft_d_two_connect2_p(t_d_two *d_standard, t_d_two *d_new)
{
	if (!d_standard || !d_new)
		return (d_new);
	d_standard->connect2_p = d_new;
	d_new->connect2_m = d_standard;
	d_new->head2 = d_standard->head2;
	d_new->coordinate_1 = d_standard->coordinate_1;
	d_new->coordinate_2 = d_standard->coordinate_2 + 1;
	return (d_new);
}

t_d_two	*ft_d_two_connect2_m(t_d_two *d_standard, t_d_two *d_new)
{
	if (!d_standard || !d_new)
		return (d_new);
	d_standard->connect2_m = d_new;
	d_new->connect2_p = d_standard;
	d_new->head2 = d_standard->head2;
	d_new->coordinate_1 = d_standard->coordinate_1;
	d_new->coordinate_2 = d_standard->coordinate_2 - 1;
	return (d_new);
}
