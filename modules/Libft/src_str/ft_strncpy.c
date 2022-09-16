/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:06:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/06/26 20:07:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *str, size_t len)
{
	char	*tmp;
	char	*result;

	if (len == 0)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) *(len + 1));
	if (!tmp)
		return (NULL);
	result = tmp;
	tmp[len] = '\0';
	while (len--)
		*tmp++ = *str++;
	return (result);
}
