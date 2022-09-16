/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:04:06 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:01:41 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 
	url :: https://en.wikipedia.org/wiki/Trigonometric_functions
	vidio :: https://www.youtube.com/watch?v=QdLVYN4rNNI
*/
/* ************************************************************************** */

#include <ft_math.h>

double	ft_sin(double angle)
{
	double	sin;
	double	temp;
	double	p;
	int		num;
	int		repeat;

	sin = 0;
	p = -1;
	num = 1;
	angle = ft_cycle(angle, C_PI);
	temp = angle;
	repeat = ft_max(7, ft_abs(angle * 7));
	while (num < repeat)
	{
		p *= -1;
		sin += temp * p;
		temp = (temp * angle * angle) / ((4 * num * num) + 2 * num);
		num++;
	}
	return (sin);
}

double	ft_sin_plus(double angle1, double angle2)
{
	double	result;

	angle1 = ft_cycle(angle1, C_PI);
	angle2 = ft_cycle(angle2, C_PI);
	result = ft_sin(angle1) * ft_cos(angle2) + ft_cos(angle1) * ft_sin(angle2);
	return (result);
}

double	ft_sin_minus(double angle1, double angle2)
{
	double	result;

	angle1 = ft_cycle(angle1, C_PI);
	angle2 = ft_cycle(angle2, C_PI);
	result = ft_sin(angle1) * ft_cos(angle2) - ft_cos(angle1) * ft_sin(angle2);
	return (result);
}

double	ft_cosec(double angle)
{
	double	sin;

	sin = ft_sin(angle);
	if (!sin)
		return (1 / 1.7976931348623157e+308);
	return (1 / sin);
}
