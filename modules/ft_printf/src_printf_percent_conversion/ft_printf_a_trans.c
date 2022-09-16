/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_a_trans.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:38:56 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 17:54:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

void	ft_ft_printf_a_front(union u_floatbit c_floatbit, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax, int *len)
{
	char				*free_tmp;

	free_tmp = "";
	if (c_floatbit.s_bit.sign)
		free_tmp = "-";
	*len = c_syntax.precision;
	if (c_syntax.precision < 0)
		*len = 13;
	if (c_syntax.precision != 0 && c_syntax.precision++)
		(*c_printf_percent)->front = ft_strjoin(free_tmp, "0x1.");
	else
		(*c_printf_percent)->front = ft_strjoin(free_tmp, "0x1");
}

void	ft_ft_printf_a_center(t_printf_percent **c_printf_percent, \
	char *free_tmp, int len)
{
	char	*tmp;

	tmp = (*c_printf_percent)->center;
	ft_memset((*c_printf_percent)->center, '0', len);
	(*c_printf_percent)->center[len] = '\0';
	while (len-- && *free_tmp)
	{
		if (len == 0)
		{
			if (free_tmp[1] > '7')
				*free_tmp += 1;
		}
		*tmp++ = *free_tmp++;
	}
}

void	ft_printf_a_trans(long double num, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax)
{
	union u_floatbit	c_floatbit;
	char				*free_tmp;
	int					len;

	c_floatbit.num = num;
	ft_ft_printf_a_front(c_floatbit, c_printf_percent, c_syntax, &len);
	(*c_printf_percent)->len += len + 3;
	ft_itoa_base(c_floatbit.s_bit.mant, &free_tmp, 16);
	(*c_printf_percent)->center = malloc(len + 1);
	if (!(*c_printf_percent)->center)
		return ;
	(*c_printf_percent)->center[len] = '\0';
	ft_ft_printf_a_center(c_printf_percent, free_tmp, len);
	free(free_tmp);
	(*c_printf_percent)->len += \
		ft_itoa_base(c_floatbit.s_bit.expt - 1023, &free_tmp, 10) + 2;
	if (*free_tmp != '-')
		(*c_printf_percent)->back = ft_strjoin("p+", free_tmp);
	else
		(*c_printf_percent)->back = ft_strjoin("p", free_tmp);
	free(free_tmp);
}
