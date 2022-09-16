/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:41:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 16:38:30 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

int	ft_printf_flag(char **str)
{
	int	bit;

	bit = ft_strchr_index("#0- +_", *(*str)++);
	if (bit)
		return (1 << (bit - 1));
	return (0);
}
