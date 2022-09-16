/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_two_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:48:28 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:48:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_two	*ft_d_two_new(t_d_one *d_1)
{
	t_d_two	*d_new;

	d_new = (t_d_two *)malloc(sizeof(t_d_two));
	if (!d_new)
		return (NULL);
	ft_memset(d_new, 0, sizeof(t_d_two));
	d_new->d_0 = d_1->d_0;
	d_new->d_1 = d_1;
	d_new->head1 = d_new;
	d_new->head2 = d_new;
	return (d_new);
}
