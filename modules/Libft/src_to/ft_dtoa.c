/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:00:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/15 11:35:03 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_dtoa_len(long double value, int max_len);

int	ft_dtoa(long double value, char **str, int max_len)
{
	char		*str_decimal;
	long double	tmp;
	int			len;

	tmp = value;
	len = ft_dtoa_len(value, max_len);
	str_decimal = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_decimal)
		return (0);
	*str = str_decimal;
	str_decimal[0] = 0x30;
	tmp = value;
	while (len--)
	{
		tmp *= 10;
		*str_decimal++ = (int)tmp - 10 + 0x30;
		tmp = tmp - (int)tmp + 1;
		if (len == 0 && tmp - 1 > 0.5)
			(*str_decimal)++;
	}
	*str_decimal = '\0';
	return (str_decimal - *str);
}

int	ft_dtoa_len(long double value, int max_len)
{
	int	len;

	len = 0;
	while (value && max_len-- && ++len)
	{
		value *= 10;
		value = value - (int)value + 1;
	}
	return (len);
}
