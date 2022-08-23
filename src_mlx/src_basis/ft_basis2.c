/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basis2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:35:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 13:35:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_basis.h>

t_basis2	*ft_new_basis2(t_vec2 v2_1, t_vec2 v2_2)
{
	t_basis2	*new;

	new = (t_basis2 *)malloc(sizeof(t_basis2));
	if (!new)
		return (NULL);
	new->basis_1 = v2_1;
	new->basis_2 = v2_2;
	return (new);
}

t_basis2	*ft_basis2_init(void)
{
	t_vec2	v2_1;
	t_vec2	v2_2;

	v2_1 = ft_vector_2(1, 0);
	v2_2 = ft_vector_2(0, 1);
	return (ft_new_basis2(v2_1, v2_2));
}

t_basis2	*ft_basis2_set(t_basis2 *basis2, t_vec2 v2_1, t_vec2 v2_2)
{
	basis2->basis_1 = v2_1;
	basis2->basis_2 = v2_2;
	return (basis2);
}

t_vec2	ft_basis2_transform(t_basis2 *basis2, t_vec2 v2)
{
	v2 = ft_vec2_sum(\
		ft_vec2_mult(basis2->basis_1, v2.x), \
		ft_vec2_mult(basis2->basis_2, v2.y) \
		);
	return (v2);
}
