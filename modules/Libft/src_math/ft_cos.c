/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:04:06 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/20 12:01:23 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*
	url :: https://en.wikipedia.org/wiki/Trigonometric_functions
	video :: https://www.youtube.com/watch?v=QdLVYN4rNNI
*/
/* ************************************************************************** */

#include <ft_math.h>

double	ft_cos(double angle)
{
	double	cos;
	double	temp;
	double	p;
	int		num;
	int		repeat;

	cos = 0;
	p = 1;
	num = 1;
	angle = ft_cycle(angle, C_PI);
	temp = 1;
	repeat = ft_max(7, ft_abs(angle * 8));
	while (num < repeat)
	{
		p *= -1;
		cos += temp * p;
		temp = (temp * angle * angle) / ((4 * num * num) - 2 * num);
		num++;
	}
	return (-cos);
}

double	ft_cos_plus(double angle1, double angle2)
{
	double	result;

	angle1 = ft_cycle(angle1, C_PI);
	angle2 = ft_cycle(angle2, C_PI);
	result = ft_cos(angle1) * ft_cos(angle2) - ft_sin(angle1) * ft_sin(angle2);
	return (result);
}

double	ft_cos_minus(double angle1, double angle2)
{
	double	result;

	angle1 = ft_cycle(angle1, C_PI);
	angle2 = ft_cycle(angle2, C_PI);
	result = ft_cos(angle1) * ft_cos(angle2) + ft_sin(angle1) * ft_sin(angle2);
	return (result);
}

double	ft_sec(double angle)
{
	double	cos;

	cos = ft_cos(angle);
	if (!cos)
		return (1 / 1.7976931348623157e+308);
	return (1 / cos);
}
