/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:33:23 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/25 11:46:45 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	s_len;

	if (s == (void *)0 || f == (void *)0)
		return ((void *)0);
	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (s_len + 1));
	if (str == NULL)
		return (NULL);
	s_len = 0;
	while (s[s_len] != '\0')
	{
		str[s_len] = f(s_len, s[s_len]);
		s_len++;
	}
	str[s_len] = '\0';
	return (str);
}
