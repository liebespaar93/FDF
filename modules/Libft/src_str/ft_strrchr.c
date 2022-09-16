/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:40:30 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 12:37:40 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	long unsigned int	s_len;

	s_len = ft_strlen(s) + 1;
	while (c > 255)
		c -= 256;
	while (s_len-- > 0)
	{
		if (s[s_len] == c)
			return ((char *)(s + s_len));
	}
	return ((void *)0);
}
