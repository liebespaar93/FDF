/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:04:06 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:01:44 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 
	url :: https://en.wikipedia.org/wiki/Trigonometric_functions
    url :: https://rosettacode.org/wiki/Bernoulli_numbers#C
*/
/* ************************************************************************** */

#include <ft_math.h>

double	ft_tan(double angle)
{
	double	tan;

	tan = ft_sin(angle) / ft_cos(angle);
	return (tan);
}

double	ft_tan_plus(double angle1, double angle2)
{
	double	result;

	angle1 = ft_cycle(angle1, C_PI);
	angle2 = ft_cycle(angle2, C_PI);
	result = (ft_tan(angle1) + ft_tan(angle2)) / \
		(1 - ft_tan(angle1) * ft_tan(angle2));
	return (result);
}

double	ft_tan_minus(double angle1, double angle2)
{
	double	result;

	angle1 = ft_cycle(angle1, C_PI);
	angle2 = ft_cycle(angle2, C_PI);
	result = (ft_tan(angle1) - ft_tan(angle2)) / \
		(1 + ft_tan(angle1) * ft_tan(angle2));
	return (result);
}

double	ft_cot(double angle)
{
	double	tan;

	tan = ft_tan(angle);
	if (!tan)
		return (1 / 1.7976931348623157e+308);
	return (1 / tan);
}
