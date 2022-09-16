/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:19:13 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/15 11:40:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PERCENT_H
# define FT_PRINTF_PERCENT_H

# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>

typedef struct s_syntax
{
	short	flags;
	int		width;
	int		precision;
	char	*length;
}	t_syntax;

typedef struct s_printf_percent
{
	int		len;
	char	sign;
	char	*bit;
	char	*front;
	char	*center;
	char	*back;
}	t_printf_percent;

typedef union u_floatbit
{
	long double	num;
	struct
	{
		unsigned long long int	mant :52 ;
		unsigned short			expt :11 ;
		unsigned char			sign :1 ;
	}	s_bit;
}	t_floatbit;

typedef long long int			t_intmax;
typedef unsigned long long int	t_uintmax;
typedef long long int			t_ptrdiff;

int		ft_printf(char *str, ...);

/* src_printf */
char	*ft_printf_percent(char **str, va_list *va, \
	va_list va_origin, int *len);

/* src_printf_percent */

int		ft_printf_asterisk(char **str, va_list *va, \
	va_list va_origin);
char	*ft_printf_conversion(char **str, va_list *va, \
	t_syntax c_syntax, int *len);
int		ft_printf_flag(char **str);
char	*ft_printf_length(char **str, char *length);
void	ft_printf_num_type(char **str, t_syntax *c_syntax, \
	va_list *va, va_list va_origin);
int		ft_printf_precision(char **str, va_list *va, va_list va_origin);
int		ft_printf_width(char **str, va_list *va, va_list va_origin);

/* src_printf_percent_conversion */

void	ft_printf_cs(char **str, va_list *va, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax);
void	ft_printf_dioux(char **str, va_list *va, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax);
void	ft_printf_fega(char **str, va_list *va, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax);
void	ft_printf_n(va_list *va, t_syntax *c_syntax, int *len);
void	ft_printf_p(va_list *va, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax);
int		ft_printf_syntax_error(t_syntax *c_syntax);
char	*ft_printf_syntaxing(char **str, \
	t_printf_percent *c_printf_percent, t_syntax c_syntax);
void	ft_printf_a_trans(long double num, \
	t_printf_percent **c_printf_percent, t_syntax c_syntax);

/* src */
int		ft_va_arg_index(va_list *va, va_list va_origin, int n, int option);
#endif
