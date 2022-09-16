/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_syntaxing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:54:09 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 18:13:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

char	*ft_printf_syntax_str(t_printf_percent *c_printf_percent, \
	t_syntax c_syntax);
char	*ft_printf_percent_malloc(t_printf_percent *c_printf_percent);
void	ft_printf_right_sign(char **result, char **precision, \
	t_syntax c_syntax, t_printf_percent *c_printf_percent);
void	ft_printf_syntax_zero(t_printf_percent *c_printf_percent, \
	t_syntax c_syntax);

char	*ft_printf_syntaxing(char **str, \
	t_printf_percent *c_printf_percent, t_syntax c_syntax)
{
	if (c_syntax.flags & 0x01 && ft_strncmp(c_printf_percent->center, "0", 2))
	{
		if (ft_strchr_index("oO", **str) && c_printf_percent->len++)
			c_printf_percent->bit = "0";
		else if (ft_strchr_index("xX", **str))
		{
			c_printf_percent->len += 2;
			c_printf_percent->bit = "0x";
			if ('X' == **str)
				c_printf_percent->bit = "0X";
		}
	}
	if (c_syntax.flags & 0x08)
		if (!c_printf_percent->sign && ++c_printf_percent->len)
			c_printf_percent->sign = ' ';
	if (c_syntax.flags & 0x10 && ft_strchr_index("dDi", **str))
	{
		if (!c_printf_percent->sign)
			c_printf_percent->len++;
		if (c_printf_percent->sign != '-')
			c_printf_percent->sign = '+';
	}
	if (c_syntax.flags & 0x02 || !ft_strchr_index("csCn", **str))
		ft_printf_syntax_zero(c_printf_percent, c_syntax);
	return (ft_printf_syntax_str(c_printf_percent, c_syntax));
}

void	ft_printf_syntax_zero(t_printf_percent *c_printf_percent, \
	t_syntax c_syntax)
{
	char	*str_precision;
	int		empty_len;
	int		len;

	len = ft_strlen(c_printf_percent->center);
	empty_len = c_syntax.precision - len;
	if (empty_len > 0)
	{
		str_precision = (char *)malloc(len + empty_len + 1);
		if (!str_precision)
			return ;
		ft_memset(str_precision, '0', len + empty_len);
		ft_strlcpy(str_precision + empty_len, \
			c_printf_percent->center, len + empty_len);
		str_precision[len + empty_len] = '\0';
		free(c_printf_percent->center);
		c_printf_percent->center = str_precision;
		c_printf_percent->len += empty_len;
	}
}

char	*ft_printf_syntax_str(t_printf_percent *c_printf_percent, \
	t_syntax c_syntax)
{
	char	*result;
	char	*precision;

	precision = ft_printf_percent_malloc(c_printf_percent);
	if (c_syntax.width <= c_printf_percent->len)
		return (precision);
	result = (char *)malloc(c_syntax.width + 1);
	if (!result)
		return (NULL);
	ft_printf_right_sign(&result, &precision, c_syntax, c_printf_percent);
	result[c_syntax.width] = '\0';
	if (c_syntax.flags & 0x04)
		ft_memcpy(result, precision, c_printf_percent->len);
	else
		ft_strcpy(result + (c_syntax.width - c_printf_percent->len), precision);
	free(precision);
	c_printf_percent->len += c_syntax.width - c_printf_percent->len;
	return (result);
}

char	*ft_printf_percent_malloc(t_printf_percent *c_printf_percent)
{
	char	*result;
	char	*result_ptr;

	result = (char *)malloc(c_printf_percent->len + 1);
	if (!result)
		return (NULL);
	result_ptr = result;
	if (c_printf_percent->sign)
		*result_ptr++ = c_printf_percent->sign;
	if (c_printf_percent->bit)
		ft_strmcpy(&result_ptr, c_printf_percent->bit);
	if (c_printf_percent->front)
		ft_strmcpy(&result_ptr, c_printf_percent->front);
	if (c_printf_percent->center)
		ft_strmcpy(&result_ptr, c_printf_percent->center);
	if (c_printf_percent->back)
		ft_strmcpy(&result_ptr, c_printf_percent->back);
	*result_ptr = '\0';
	return (result);
}

void	ft_printf_right_sign(char **result, char **precision, \
	t_syntax c_syntax, t_printf_percent *c_printf_percent)
{
	if (c_syntax.flags & 0x02 && c_syntax.precision == -1)
	{
		ft_memset(*result, '0', c_syntax.width);
		if (c_printf_percent->sign)
		{
			**result = c_printf_percent->sign;
			**precision = '0';
		}
	}
	else
		ft_memset(*result, ' ', c_syntax.width);
}
