/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:23:38 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 12:39:50 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		if (n < -2147483647)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n *= -1;
	}
	num = (n % 10) + '0';
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &num, 1);
}
