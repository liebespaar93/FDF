/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:28:59 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 13:35:02 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASIS_H
# define FT_BASIS_H

# include <ft_vector.h>

typedef struct s_basis2	t_basis2;

typedef struct s_basis2
{
	t_vec2	basis_1;
	t_vec2	basis_2;
}	t_basis2;

t_basis2	*ft_new_basis2(t_vec2 v2_1, t_vec2 v2_2);
t_basis2	*ft_basis2_init(void);
t_basis2	*ft_basis2_set(t_basis2 *basis2, t_vec2 v2_1, t_vec2 v2_2);
t_vec2		ft_basis2_transform(t_basis2 *basis, t_vec2 v2);

#endif