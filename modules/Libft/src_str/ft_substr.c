/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:59 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/25 11:52:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	s_len;
	char	*str;

	if (s == (void *)0)
		return (ft_calloc(1, sizeof(char)));
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_calloc(1, 1));
	if (s_len < len)
		len = s_len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	s_len = 0;
	while (len-- && s[start + s_len] != '\0')
	{
		str[s_len] = s[start + s_len];
		s_len++;
	}
	str[s_len] = '\0';
	return (str);
}
