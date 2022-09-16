/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:52:57 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 14:28:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	long unsigned int	s_len;

	if (s == (void *)0)
		return ;
	s_len = 0;
	while (s[s_len] != '\0')
	{
		f(s_len, &s[s_len]);
		s_len++;
	}
}
