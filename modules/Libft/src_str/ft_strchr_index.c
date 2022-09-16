/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:43:43 by kyoulee           #+#    #+#             */
/*   Updated: 2022/06/10 07:43:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr_index(char *str, char c)
{
	char	*tmp;

	tmp = str;
	while (*tmp != 0x00)
		if (*tmp++ == c)
			return (tmp - str);
	return (0);
}
