/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:24:57 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/17 17:39:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*strdup_ptr;
	size_t	s1_len;

	strdup_ptr = (char *)s1;
	if (s1 == (void *)0)
		*strdup_ptr = '\0';
	s1_len = ft_strlen(s1);
	strdup_ptr = (char *)malloc(1 * (s1_len + 1));
	if (strdup_ptr == NULL)
		return (NULL);
	while (*s1 != '\0')
		*strdup_ptr++ = *s1++;
	*strdup_ptr = '\0';
	return (strdup_ptr - s1_len);
}
