/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:00:43 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 18:13:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

void	ft_printf_p(va_list *va, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax)
{
	void	*a;
	char	*tmp;

	a = va_arg(*va, void *);
	(*c_printf_percent)->len += \
		ft_itoa_base((unsigned long long int)a, &tmp, 16) + 2;
	(*c_printf_percent)->front = ft_strjoin("0x", "");
	(*c_printf_percent)->center = tmp;
	if (a == 0 && c_syntax.precision == 0)
	{
		(*c_printf_percent)->len -= ft_strlen((*c_printf_percent)->center);
		free ((*c_printf_percent)->center);
		(*c_printf_percent)->center = malloc(1);
		if ((*c_printf_percent)->center)
			(*c_printf_percent)->center[0] = '\0';
	}
}
