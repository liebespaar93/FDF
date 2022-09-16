/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_four_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:45:14 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:45:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_four	*ft_d_four_new(t_d_three *d_3)
{
	t_d_four	*d_new;

	if (!d_3)
		return (NULL);
	d_new = (t_d_four *)malloc(sizeof(t_d_four));
	if (!d_new)
		return (NULL);
	ft_memset(d_new, 0, sizeof(t_d_four));
	d_new->d_0 = d_3->d_0;
	d_new->d_3 = d_3;
	d_new->head1 = d_new;
	d_new->head2 = d_new;
	d_new->head3 = d_new;
	d_new->head4 = d_new;
	return (d_new);
}
