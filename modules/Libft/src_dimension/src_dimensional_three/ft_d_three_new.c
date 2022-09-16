/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_three_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:47:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:47:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_three	*ft_d_three_new(t_d_two *d_2)
{
	t_d_three	*d_new;

	if (!d_2)
		return (NULL);
	d_new = (t_d_three *)malloc(sizeof(t_d_three));
	if (!d_new)
		return (NULL);
	ft_memset(d_new, 0, sizeof(t_d_three));
	d_new->d_0 = d_2->d_0;
	d_new->d_2 = d_2;
	d_new->head1 = d_new;
	d_new->head2 = d_new;
	d_new->head3 = d_new;
	return (d_new);
}
