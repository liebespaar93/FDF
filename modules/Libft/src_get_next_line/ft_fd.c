/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:45:30 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/01 14:45:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <libft.h>

int	ft_open(char *filename, int option)
{
	int		fd;

	fd = open(filename, option);
	if (fd < 0 && write(2, "fd_error\n", 9))
		exit(1);
	return (fd);
}

int	ft_open_type(char *filename, int option, char *type)
{
	int		fd;
	int		len[2];

	len[0] = ft_strlen(filename);
	len[1] = ft_strlen(type);
	if (len[0] <= len[1] && ft_error_m("type_error"))
		exit(1);
	if (ft_memcmp(filename + len[0] - len[1], type, len[1]) && \
		ft_error_m("type_error"))
		exit(1);
	fd = open(filename, option);
	if (fd < 0 && write(2, "fd_error\n", 9))
		exit(1);
	return (fd);
}
