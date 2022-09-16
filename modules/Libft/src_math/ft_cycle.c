/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:58:43 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:21:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

double	ft_cycle(double value, double cycle)
{
	double	abs_cycle;

	abs_cycle = ft_abs(cycle);
	while (value < -abs_cycle)
		value += abs_cycle * 2;
	while (value > abs_cycle)
		value -= abs_cycle * 2;
	return (value);
}
