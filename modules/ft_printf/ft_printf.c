/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:14:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 17:44:24 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_printf_percent.h>

void	ft_printf_write(char *str, va_list *va, va_list va_origin, int *len);

int	ft_printf(char *str, ...)
{
	va_list	va_origin;
	va_list	va;
	int		len;

	va_start(va, str);
	va_copy(va_origin, va);
	len = 0;
	ft_printf_write(str, &va, va_origin, &len);
	va_end(va);
	va_end(va_origin);
	return (len);
}

void	ft_printf_write(char *str, va_list *va, va_list va_origin, int *len)
{
	char	*str_percent;
	char	*tmp;
	int		str_len;
	int		tmp_len;

	tmp = str;
	while (*tmp != '\0' && *len > -1)
	{
		if (*tmp != '%' && ++(*len))
			tmp++;
		else
		{
			str_len = tmp - str;
			tmp_len = *len;
			str_percent = ft_printf_percent(&tmp, va, va_origin, len);
			if (*len < 0 || !str_percent)
				break ;
			write(1, str, str_len);
			write(1, str_percent, *len - tmp_len);
			free(str_percent);
			str = tmp;
		}
	}
	if (*len > -1)
		write(1, str, tmp - str);
}
