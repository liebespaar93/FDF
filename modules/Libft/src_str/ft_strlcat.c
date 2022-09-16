/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:05:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/17 18:37:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	empty_size;

	if (dst == (void *)0 || src == (void *)0)
		*dst = '\0';
	slen = ft_strlen(src);
	empty_size = dstsize;
	while (*dst != '\0' && empty_size > 0)
	{
		dst++;
		empty_size--;
	}
	dlen = dstsize - empty_size;
	if (empty_size)
	{
		if (slen < empty_size - 1)
			empty_size = slen + 1;
		dst = ft_memcpy(dst, src, empty_size - 1);
		dst[empty_size - 1] = '\0';
	}
	return (dlen + slen);
}
