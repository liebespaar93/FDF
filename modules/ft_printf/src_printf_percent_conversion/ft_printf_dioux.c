/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dioux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:58:14 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 18:13:45 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

__int128			ft_printf_dioux_di_arg(va_list *va, t_syntax c_syntax);
__int128			ft_printf_dioux_oux_arg(va_list *va, t_syntax c_syntax);
unsigned __int128	ft_printf_dioux_arg(char **str, va_list *va, \
	t_syntax c_syntax, t_printf_percent **c_printf_percent);

void	ft_printf_dioux(char **str, va_list *va, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax)
{
	unsigned __int128	num;
	char				**tmp;

	num = ft_printf_dioux_arg(str, va, c_syntax, c_printf_percent);
	tmp = &(*c_printf_percent)->center;
	if (**str == 'd' || **str == 'D' || **str == 'i')
		(*c_printf_percent)->len += ft_itoa_base(num, tmp, 10);
	else if (**str == 'o' || **str == 'O')
		(*c_printf_percent)->len += ft_itoa_base(num, tmp, 8);
	else if (**str == 'u' || **str == 'U')
		(*c_printf_percent)->len += ft_itoa_base(num, tmp, 10);
	else if (**str == 'x' || **str == 'X')
		(*c_printf_percent)->len += ft_itoa_base(num, tmp, 16);
	if (**str == 'X')
		ft_str_upper((*c_printf_percent)->center);
	if (num == 0 && c_syntax.precision == 0)
	{
		(*c_printf_percent)->len -= ft_strlen((*c_printf_percent)->center);
		free ((*c_printf_percent)->center);
		(*c_printf_percent)->center = malloc(1);
		if ((*c_printf_percent)->center)
			(*c_printf_percent)->center[0] = '\0';
	}
}

unsigned __int128	ft_printf_dioux_arg(char **str, va_list *va, \
	t_syntax c_syntax, t_printf_percent **c_printf_percent)
{
	unsigned __int128	num;

	if (ft_strchr_index("dDi", **str))
	{
		num = ft_printf_dioux_di_arg(va, c_syntax);
		if (num & 0x8000000000000000 && ++(*c_printf_percent)->len)
		{
			num *= -1;
			(*c_printf_percent)->sign = '-';
		}
	}
	else
		num = ft_printf_dioux_oux_arg(va, c_syntax);
	if (num < 0 && ++(*c_printf_percent)->len)
	{
		num *= -1;
		(*c_printf_percent)->sign = '-';
	}
	return (num);
}

__int128	ft_printf_dioux_di_arg(va_list *va, t_syntax c_syntax)
{
	if (!c_syntax.length)
		return (va_arg(*va, int));
	else if (ft_str_diff(c_syntax.length, "hh"))
		return (va_arg(*va, int));
	else if (ft_str_diff(c_syntax.length, "h"))
		return (va_arg(*va, int));
	else if (ft_str_diff(c_syntax.length, "l"))
		return (va_arg(*va, long));
	else if (ft_str_diff(c_syntax.length, "ll"))
		return (va_arg(*va, long long));
	else if (ft_str_diff(c_syntax.length, "j"))
		return (va_arg(*va, t_intmax));
	else if (ft_str_diff(c_syntax.length, "z"))
		return (va_arg(*va, size_t));
	else if (ft_str_diff(c_syntax.length, "t"))
		return (va_arg(*va, t_ptrdiff));
	else
		return (va_arg(*va, int));
}

__int128	ft_printf_dioux_oux_arg(va_list *va, t_syntax c_syntax)
{
	if (!c_syntax.length)
		return (va_arg(*va, unsigned int));
	else if (ft_str_diff(c_syntax.length, "hh"))
		return (va_arg(*va, unsigned int));
	else if (ft_str_diff(c_syntax.length, "h"))
		return (va_arg(*va, unsigned int));
	else if (ft_str_diff(c_syntax.length, "l"))
		return (va_arg(*va, unsigned long));
	else if (ft_str_diff(c_syntax.length, "ll"))
		return (va_arg(*va, unsigned long long));
	else if (ft_str_diff(c_syntax.length, "j"))
		return (va_arg(*va, t_intmax));
	else if (ft_str_diff(c_syntax.length, "z"))
		return (va_arg(*va, size_t));
	else if (ft_str_diff(c_syntax.length, "t"))
		return (va_arg(*va, t_ptrdiff));
	else
		return (va_arg(*va, unsigned int));
}
