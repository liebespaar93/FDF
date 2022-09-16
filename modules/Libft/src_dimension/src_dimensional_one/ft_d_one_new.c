/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_one_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:51:42 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 16:49:13 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_one	*ft_d_one_new(t_d_zero *d_0)
{
	t_d_one	*d_new;

	d_new = (t_d_one *)malloc(sizeof(t_d_one));
	if (!d_new)
		return (NULL);
	ft_memset(d_new, 0, sizeof(t_d_one));
	d_new->d_0 = d_0;
	d_new->head1 = d_new;
	return (d_new);
}
