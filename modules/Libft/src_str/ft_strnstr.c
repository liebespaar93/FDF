/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:34:49 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 14:47:56 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_ptr;
	char	*needle_ptr;
	size_t	len_temp;

	haystack_ptr = (char *)haystack;
	needle_ptr = (char *)needle;
	if (*needle == '\0' || needle == haystack)
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		haystack_ptr = (char *)haystack;
		needle_ptr = (char *)needle;
		len_temp = len--;
		while (*haystack_ptr++ == *needle_ptr++ && len_temp-- > 0)
		{
			if (*needle_ptr == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return ((void *)0);
}
