/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_diff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:32:39 by kyoulee           #+#    #+#             */
/*   Updated: 2022/06/10 08:11:56 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_diff(char *str, char *src)
{
	char	*tmp;

	tmp = str;
	if (!str)
		return (0);
	while (*tmp != '\0' && *src != '\0')
	{
		if (*tmp != *src)
			break ;
		tmp++;
		src++;
	}
	if (*src != '\0')
		return (0);
	return (1);
}
