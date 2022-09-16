/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:10:10 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/07 01:11:23 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_index_b(char str)
{
	int		num;

	num = 0;
	if (0x30 <= str && str <= 0x39)
		num = str - 0x30;
	else if (0x41 <= str && str <= 0x5a)
		num = 10 + str - 0x41;
	else if (0x61 <= str && str <= 0x7a)
		num = 10 + str - 0x61;
	return (num);
}

int	ft_atoi_base(char **str_ptr)
{
	char	*str;
	int		num;

	str = *str_ptr;
	num = 0;
	if (!ft_strncmp(str, "0x", 2))
	{
		str += 2;
		while (ft_isalnum(*str))
		{
			if (num > num * 16)
				return (0);
			num = num * 16 + ft_index_b(*str);
			str++;
		}
	}
	else
		num = ft_atoi(str);
	*str_ptr = str;
	return (num);
}
