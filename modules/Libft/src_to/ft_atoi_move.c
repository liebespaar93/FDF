/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:09:40 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/07 02:33:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi_move(char **str_ptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (!(**str_ptr == '-' || **str_ptr == '+' || \
		(0x30 <= **str_ptr && **str_ptr <= 0x39)))
		(*str_ptr)++;
	if ((**str_ptr == '-' || **str_ptr == '+'))
	{
		if (**str_ptr == '-')
			sign = -1;
		(*str_ptr)++;
	}
	while (0x30 <= **str_ptr && **str_ptr <= 0x39)
	{
		if (num > num * 10)
			return (ft_atoi_overflow(sign));
		num = (num * 10) + (**str_ptr - 0x30);
		(*str_ptr)++;
	}
	return (num * sign);
}
