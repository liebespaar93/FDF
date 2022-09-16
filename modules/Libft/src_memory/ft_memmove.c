/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:50:51 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 15:02:59 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (dst == (void *)0 && src == (void *)0)
		return ((void *)0);
	else if (src == (void *)0)
		*dptr = *sptr;
	if (dst > src)
		while (len-- > 0)
			dptr[len] = sptr[len];
	else
		while (len-- > 0)
			*dptr++ = *sptr++;
	return ((void *)dst);
}
