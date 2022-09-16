/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:06:59 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 14:51:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	str_len;

	if (s1 == (void *)0 || set == (void *)0)
		return ((void *)0);
	str_len = ft_strlen(s1);
	while (str_len > 0)
	{
		if (ft_strchr(set, s1[str_len - 1]))
			str_len--;
		else if (ft_strchr(set, *s1))
		{
			str_len--;
			s1++;
		}
		else
			break ;
	}
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return ((void *)0);
	str[str_len] = '\0';
	while (str_len-- > 0)
		str[str_len] = s1[str_len];
	return (str);
}
