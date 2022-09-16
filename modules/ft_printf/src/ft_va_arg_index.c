/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:47:38 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 16:38:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

int	ft_va_arg_index(va_list *va, va_list va_origin, int n, int option)
{
	int	num;

	if (n < 0)
		return (0x7FFFFFFF);
	if (n == 0)
		return (0);
	while (n-- > 1)
		num = va_arg(va_origin, int);
	if (option)
	{
		va_end(*va);
		va_copy(*va, va_origin);
	}
	num = va_arg(va_origin, int);
	return (num);
}
