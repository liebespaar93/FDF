/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:09:40 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 19:40:25 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_atoi_len(char *str)
{
	size_t	len;
	int		flag;

	flag = 1;
	len = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			if (flag)
				len++;
			flag = 0;
		}
		else
			flag = 1;
		str++;
	}
	return (len);
}

size_t	ft_atoi_arr(int **atoi_arr_ptr, char *str)
{
	int		*atoi_arr;
	size_t	index;
	int		len;

	index = 0;
	len = ft_atoi_len(str);
	if (!ft_zeromalloc((void **)&atoi_arr, sizeof(int) * (len)))
		return (0);
	while (len--)
		atoi_arr[index++] = ft_atoi_move(&str);
	*atoi_arr_ptr = atoi_arr;
	return (index);
}
