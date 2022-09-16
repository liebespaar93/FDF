/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:47:20 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/23 00:58:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

void	ft_printf_cs(char **str, va_list *va, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax)
{
	char	*tmp;

	if (ft_strchr_index("cC", **str) && ++(*c_printf_percent)->len)
	{
		tmp = (char *)malloc(2);
		tmp[0] = va_arg(*va, int);
		tmp[1] = '\0';
		(*c_printf_percent)->center = tmp;
	}
	else if (**str == 's')
	{
		tmp = va_arg(*va, char *);
		if (!tmp)
			tmp = "(null)";
		(*c_printf_percent)->len = ft_strlen(tmp);
		if (c_syntax.precision != -1)
			(*c_printf_percent)->len = c_syntax.precision;
		(*c_printf_percent)->center = malloc((*c_printf_percent)->len + 1);
		if (!(*c_printf_percent)->center)
			return ;
		(*c_printf_percent)->center[(*c_printf_percent)->len] = '\0';
		ft_strlcpy((*c_printf_percent)->center, tmp, \
			(*c_printf_percent)->len + 1);
		(*c_printf_percent)->center[(*c_printf_percent)->len] = '\0';
	}
}
