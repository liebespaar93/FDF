/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:56:27 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/01 16:56:28 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_ptrlen(void **ptr, char *type)
{
	int	len;

	len = 0;
	if (!ft_strcmp(type, "int **"))
		while (*((int **)(*ptr) + len))
			len++;
	else if (!ft_strcmp(type, "float **"))
		while (*((float **)(*ptr) + len))
			len++;
	else if (!ft_strcmp(type, "char **"))
		while (*((char **)(*ptr) + len))
			len++;
	return (len);
}
