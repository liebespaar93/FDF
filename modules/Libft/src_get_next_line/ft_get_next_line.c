/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:00:41 by kyoulee           #+#    #+#             */
/*   Updated: 2022/06/26 19:22:24 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_get_next_line.h>

char	*ft_buff_split(char **buff_all, int *flag, int rlen)
{
	char	*tmp;
	char	*result;
	int		enter_len;
	int		leave_len;

	enter_len = 0;
	leave_len = 0;
	tmp = *buff_all;
	while (*tmp && ++enter_len && rlen--)
		if (*tmp++ == '\n' && (*flag)--)
			break ;
	while (*tmp++ && rlen--)
		leave_len++;
	if (!leave_len)
	{
		result = *buff_all;
		*buff_all = NULL;
		return (result);
	}
	result = ft_strncpy(*buff_all, enter_len);
	tmp = ft_strncpy(*buff_all + enter_len, leave_len);
	free(*buff_all);
	*buff_all = tmp;
	return (result);
}

void	ft_buff_read(char **buff_static, t_list **buff_head, int *flag, int fd)
{
	int		rlen;

	*buff_static = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buff_static)
		return ;
	rlen = (int)read(fd, *buff_static, BUFFER_SIZE);
	if (rlen <= 0)
	{
		free(*buff_static);
		*buff_static = NULL;
		*flag = 0;
		return ;
	}
	(*buff_static)[rlen] = '\0';
	ft_lstadd_back(buff_head, \
		ft_lstnew(ft_buff_split(buff_static, flag, rlen)));
}

t_fd	*ft_lst_fd_addfront(t_fd **fd_static, int fd, char **buff_static)
{
	t_fd	*new;

	new = (t_fd *)malloc(sizeof(t_fd));
	if (!new)
		return (*fd_static);
	new->fd = fd;
	new->data = *buff_static;
	new->next = NULL;
	if (!*fd_static)
		return (new);
	new->next = *fd_static;
	return (new);
}

char	*ft_lst_fd_find(t_fd **fd_static, int fd)
{
	t_fd	*tmp;
	t_fd	*front;
	char	*result;

	if (!*fd_static)
		return (NULL);
	result = NULL;
	front = NULL;
	tmp = *fd_static;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			result = tmp->data;
			if (front)
				front->next = tmp->next;
			else
				*fd_static = tmp->next;
			free(tmp);
			break ;
		}
		front = tmp;
		tmp = tmp->next;
	}
	return (result);
}

char	*ft_get_next_line(int fd)
{
	static t_fd		*fd_static;
	char			*buff_static;
	t_list			*buff_head;
	char			*buff;
	int				flag;

	buff_head = NULL;
	flag = 1;
	buff_static = ft_lst_fd_find(&fd_static, fd);
	if (buff_static)
		ft_lstadd_back(&buff_head, \
		ft_lstnew(ft_buff_split(&buff_static, &flag, -1)));
	while (flag)
		ft_buff_read(&buff_static, &buff_head, &flag, fd);
	buff = ft_lst_malloc(&buff_head);
	if (buff_static)
		fd_static = ft_lst_fd_addfront(&fd_static, fd, &buff_static);
	return (buff);
}
