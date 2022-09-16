/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:39:25 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/15 05:51:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char *str, ...);

/* ft_printf */
char	*ft_printf_percent(char **str, va_list *va, \
	va_list va_origin, int *len);

/* src */
size_t	ft_strlen(const char *s);

#endif
