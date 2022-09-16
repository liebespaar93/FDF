/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:50:59 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/02 17:20:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# define C_PI	3.14159265358979323846264338327950288

# include <libft.h>

/* ft_abs.c */
float	ft_abs(float num);

/* ft_sign.c */
int		ft_sign(float num);

/* ft_max.c */
double	ft_max(double value1, double value2);
float	ft_float_max(float num1, float num2);

/* ft_min.c */
double	ft_min(double value1, double value2);
float	ft_float_min(float num1, float num2);

/* ft_percent.c */
double	ft_percent(int start, int end, int current);

/* ft_cycle.c */
double	ft_cycle(double value, double cycle);

/* ft_sin.c */
double	ft_sin(double angle);
double	ft_sin_plus(double angle1, double angle2);
double	ft_sin_minus(double angle1, double angle2);
double	ft_cosec(double angle);

/* ft_cos.c */
double	ft_cos(double angle);
double	ft_cos_plus(double angle1, double angle2);
double	ft_cos_minus(double angle1, double angle2);
double	ft_sec(double angle);

/* ft_tan.c */
double	ft_tan(double angle);
double	ft_tan_plus(double angle1, double angle2);
double	ft_tan_minus(double angle1, double angle2);
double	ft_cot(double angle);

/* ft_constant_square_root.c */
double	ft_constant_square_root(int integer, int repeat);
double	ft_sqrt(float integer);

/* ft_constant_e.c */
double	ft_constant_e(int repeat);

/* ft_constant_pi.c */
double	ft_constant_pi(int repeat);

#endif