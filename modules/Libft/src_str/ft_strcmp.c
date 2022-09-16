/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:52:06 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 14:33:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1++ == *s2++)
		;
	if (s1 == NULL && s2 == NULL)
		return (0);
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
