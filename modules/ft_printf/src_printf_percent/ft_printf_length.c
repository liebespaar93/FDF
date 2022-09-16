/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:51:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 16:38:27 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_percent.h>

char	*ft_str_length(char **str);
int		ft_byte_size(char *str);

char	*ft_printf_length(char **str, char *length)
{
	char	*str_length;

	str_length = ft_str_length(str);
	if (!length)
		return (str_length);
	if (ft_byte_size(str_length) > ft_byte_size(length))
		return (str_length);
	return (length);
}

char	*ft_str_length(char **str)
{
	if (ft_str_diff(*str, "hh") && (*str)++ && (*str)++)
		return ("hh");
	else if (ft_str_diff(*str, "h") && (*str)++)
		return ("h");
	else if (ft_str_diff(*str, "ll") && (*str)++ && (*str)++)
		return ("ll");
	else if (ft_str_diff(*str, "l") && (*str)++)
		return ("l");
	else if (ft_str_diff(*str, "q") && (*str)++)
		return ("q");
	else if (ft_str_diff(*str, "L") && (*str)++)
		return ("L");
	else if (ft_str_diff(*str, "j") && (*str)++)
		return ("j");
	else if (ft_str_diff(*str, "z") && (*str)++)
		return ("z");
	else if (ft_str_diff(*str, "t") && (*str)++)
		return ("t");
	else
		return ("");
}

int	ft_byte_size(char *str)
{
	int	byte_size;

	byte_size = 0;
	if (ft_str_diff(str, "hh"))
		byte_size = sizeof(char);
	else if (ft_str_diff(str, "h"))
		byte_size = sizeof(short);
	else if (ft_str_diff(str, "ll"))
		byte_size = sizeof(long long);
	else if (ft_str_diff(str, "l"))
		byte_size = sizeof(long);
	else if (ft_str_diff(str, "q"))
		byte_size = sizeof(long long);
	else if (ft_str_diff(str, "L"))
		byte_size = 0;
	else if (ft_str_diff(str, "j"))
		byte_size = sizeof(t_intmax);
	else if (ft_str_diff(str, "z"))
		byte_size = sizeof(size_t);
	else if (ft_str_diff(str, "t"))
		byte_size = sizeof(t_ptrdiff);
	return (byte_size);
}
