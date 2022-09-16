/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 04:18:59 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/12 15:23:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_error_m(char *str)
{
	char	*str_error;

	str_error = "\e[38;5;196mERROR!! \e[38;5;226m";
	write(STDOUT_FILENO, str_error, ft_strlen(str_error));
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\e[0m\n", 5);
	return (1);
}

int	ft_warring_m(char *str)
{
	char	*str_warring;

	str_warring = "\e[38;5;201mWARRING!! \e[38;5;226m";
	write(STDOUT_FILENO, str_warring, ft_strlen(str_warring));
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\e[0m\n", 5);
	return (1);
}
