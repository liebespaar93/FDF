/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:14:49 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 16:38:42 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

char	*ft_printf_percent(char **str, va_list *va, va_list va_origin, int *len)
{
	t_syntax	c_syntax;

	(*str)++;
	ft_memset(&c_syntax, 0, sizeof(t_syntax));
	c_syntax.width = -1;
	c_syntax.precision = -1;
	while (**str != 0x00)
	{
		if (ft_strchr_index("#0- +'_", **str))
			c_syntax.flags |= ft_printf_flag(str);
		else if (ft_strchr_index(".", **str))
			c_syntax.precision = ft_printf_precision(str, va, va_origin);
		else if (ft_strchr_index("*", **str))
			c_syntax.width = ft_printf_width(str, va, va_origin);
		else if (ft_strchr_index("0123456789", **str))
			ft_printf_num_type(str, &c_syntax, va, va_origin);
		else if (ft_strchr_index("hlqLjzt", **str))
			c_syntax.length = ft_printf_length(str, c_syntax.length);
		else
			return (ft_printf_conversion(str, va, c_syntax, len));
	}
	return (0);
}
