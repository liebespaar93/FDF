/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fega.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:00:45 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 18:13:41 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

long double	ft_printf_fega_arg(va_list *va, t_syntax c_syntax);
void		ft_printf_g_tarns(long double num, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax);
void		ft_printf_a_trans(long double num, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax);
void		ft_printf_ftoa(long double num, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax);
int			ft_printf_count_e(long double *num, \
	t_printf_percent **c_printf_percent);

void	ft_printf_fega(char **str, va_list *va, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax)
{
	long double	num;
	int			e;

	if (ft_str_diff(c_syntax.length, "L"))
		num = va_arg(*va, long double);
	else
		num = va_arg(*va, double);
	if (**str == 'f' || **str == 'F')
		ft_printf_ftoa(num, c_printf_percent, c_syntax);
	else if (**str == 'e' || **str == 'E')
	{
		e = ft_printf_count_e(&num, c_printf_percent);
		ft_printf_ftoa(num, c_printf_percent, c_syntax);
		(*c_printf_percent)->back = ft_etoa(e);
	}
	else if (**str == 'g' || **str == 'G')
		ft_printf_g_tarns(num, c_printf_percent, c_syntax);
	else if (**str == 'a' || **str == 'A')
		ft_printf_a_trans(num, c_printf_percent, c_syntax);
	if (ft_strchr_index("FEGA", **str))
	{
		ft_str_upper((*c_printf_percent)->front);
		ft_str_upper((*c_printf_percent)->center);
		ft_str_upper((*c_printf_percent)->back);
	}
}

void	ft_printf_g_tarns(long double num, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax)
{
	long double	origin_num;
	int			e;

	origin_num = num;
	e = ft_printf_count_e(&num, c_printf_percent);
	if (c_syntax.precision == -1)
		c_syntax.precision = 6;
	if (c_syntax.precision > 0)
		c_syntax.precision--;
	if (c_syntax.precision >= e && e > 0)
	{
		c_syntax.precision -= e;
		ft_printf_ftoa(origin_num, c_printf_percent, c_syntax);
	}
	else if (0 > e && e > c_syntax.precision * -1)
	{
		c_syntax.precision -= e;
		ft_printf_ftoa(origin_num, c_printf_percent, c_syntax);
	}
	else
	{
		e = ft_printf_count_e(&num, c_printf_percent);
		ft_printf_ftoa(num, c_printf_percent, c_syntax);
		(*c_printf_percent)->back = ft_etoa(e);
	}
}

int	ft_printf_count_e(long double *num, t_printf_percent **c_printf_percent)
{
	int	e;

	e = 0;
	if (num < 0 && ++(*c_printf_percent)->len)
	{
		*num *= -1;
		(*c_printf_percent)->sign = '-';
	}
	while (*num > 10.0 && ++e)
		*num *= 0.1;
	if (!e)
	{
		while (!(int)*num && --e)
		{
			*num += 1;
			*num *= 10;
			*num -= 10;
		}
	}
	return (e);
}

void	ft_printf_ftoa(long double num, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax)
{
	unsigned __int128	integer;
	long double			decimal;
	char				*tmp;

	if (num < 0 && ++(*c_printf_percent)->len)
	{
		num *= -1;
		(*c_printf_percent)->sign = '-';
	}
	integer = (unsigned __int128)num;
	decimal = num - integer + 1;
	(*c_printf_percent)->len += \
		ft_itoa_base(integer, &((*c_printf_percent)->front), 10);
	if (c_syntax.precision > 0 || c_syntax.precision == -1)
	{
		if (c_syntax.precision == -1)
			c_syntax.precision = 6;
		(*c_printf_percent)->len += \
			ft_dtoa(decimal, &tmp, c_syntax.precision) + 1;
		(*c_printf_percent)->center = ft_strjoin(".", tmp);
		free(tmp);
	}
	if (c_syntax.flags & 1 && c_syntax.precision == 0 \
		&& ++(*c_printf_percent)->len)
		(*c_printf_percent)->center = ft_strjoin(".", "");
}
