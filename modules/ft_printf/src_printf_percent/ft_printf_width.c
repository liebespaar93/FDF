/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:49:12 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 16:38:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

int	ft_printf_width(char **str, va_list *va, va_list va_origin)
{
	if (**str == '*')
		return (ft_printf_asterisk(str, va, va_origin));
	return (0);
}
