/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:54:09 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 16:38:34 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

char	*ft_printf_origin(char **str, t_printf_percent **c_printf_percent);
void	ft_c_printf_percent_free(char **str, \
	t_printf_percent **c_printf_percent, int *len);

char	*ft_printf_conversion(char **str, va_list *va, \
	t_syntax c_syntax, int *len)
{
	t_printf_percent	*c_printf_percent;
	char				*result;

	c_printf_percent = (t_printf_percent *)malloc(sizeof(t_printf_percent));
	if (!c_printf_percent || ft_printf_syntax_error(&c_syntax) || **str == 'S')
	{
		*len = -1;
		return ((void *)0);
	}
	ft_memset(c_printf_percent, 0, sizeof(t_printf_percent));
	if (ft_strchr_index("dDioOuUxX", **str))
		ft_printf_dioux(str, va, &c_printf_percent, c_syntax);
	else if (ft_strchr_index("fFeEgGaA", **str))
		ft_printf_fega(str, va, &c_printf_percent, c_syntax);
	else if (ft_strchr_index("csC", **str))
		ft_printf_cs(str, va, &c_printf_percent, c_syntax);
	else if (ft_strchr_index("p", **str))
		ft_printf_p(va, &c_printf_percent, c_syntax);
	else if (ft_strchr_index("n", **str))
		ft_printf_n(va, &c_syntax, len);
	else
		c_printf_percent->center = ft_printf_origin(str, &c_printf_percent);
	result = ft_printf_syntaxing(str, c_printf_percent, c_syntax);
	ft_c_printf_percent_free(str, &c_printf_percent, len);
	return (result);
}

void	ft_c_printf_percent_free(char **str, \
	t_printf_percent **c_printf_percent, int *len)
{
	(*str)++;
	*len += (*c_printf_percent)->len;
	if ((*c_printf_percent)->front)
		free((*c_printf_percent)->front);
	if ((*c_printf_percent)->center)
		free((*c_printf_percent)->center);
	if ((*c_printf_percent)->back)
		free((*c_printf_percent)->back);
	free(*c_printf_percent);
	c_printf_percent = NULL;
}

char	*ft_printf_origin(char **str, t_printf_percent **c_printf_percent)
{
	char	*result;

	(*c_printf_percent)->len += 1;
	result = (char *)malloc(1 + 1);
	result[0] = **str;
	result[1] = '\0';
	return (result);
}
