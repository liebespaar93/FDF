/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_asterisk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:46:56 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 16:38:36 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

int	ft_printf_asterisk(char **str, va_list *va, va_list va_origin)
{
	char	*tmp;
	int		num;

	if (**str == '*' && (*str)++)
	{
		tmp = *str;
		if ((0x30 <= *tmp && *tmp <= 0x39) || *tmp == '$')
		{
			num = ft_strchr_num(&tmp);
			if (*tmp++ != '$')
				return (va_arg(*va, int));
			*str = tmp;
			return (ft_va_arg_index(va, va_origin, num, 0));
		}
		else
			return (va_arg(*va, int));
	}
	return (0);
}
