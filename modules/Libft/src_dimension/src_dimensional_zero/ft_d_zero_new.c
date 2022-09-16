/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_zero_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:50:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 14:50:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dimension.h>

t_d_zero	*ft_d_zero_new(void *data, char *data_type)
{
	t_d_zero	*d_new;

	d_new = (t_d_zero *)malloc(sizeof(t_d_zero));
	if (!d_new)
		return (NULL);
	ft_memset(d_new, 0, sizeof(t_d_zero));
	d_new->data_type = data_type;
	d_new->data = data;
	d_new->coordinate = 1;
	return (d_new);
}
