/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:39:16 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 18:25:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLY_LIST_H
# define FT_DOUBLY_LIST_H

typedef struct s_d_list	t_d_list;

typedef struct s_d_list
{
	int			*data;
	t_d_list	*next;
	t_d_list	*prev;
}	t_d_list;

typedef struct s_d_list_header
{
	t_d_list	*head;
	t_d_list	*tail;
}	t_d_list_header;

t_d_list		*ft_d_list_new(void *data);
t_d_list		*ft_d_list_del(t_d_list *lst, void (*del)(void *));
t_d_list		*ft_d_list_free(t_d_list **lst, void (*del)(void *));

t_d_list		*ft_d_list_add_next(t_d_list *standard, t_d_list *next);
t_d_list		*ft_d_list_add_prev(t_d_list *standard, t_d_list *prev);

void			ft_d_list_connect_next(t_d_list *standard, t_d_list *next);
void			ft_d_list_connect_prev(t_d_list *standard, t_d_list *next);

t_d_list_header	*ft_d_list_header_init(t_d_list *lst);
t_d_list_header	*ft_d_list_header_free(t_d_list_header **lst_header, \
	void (*del)(void *));

t_d_list_header	*ft_d_list_header_add_head(t_d_list_header *standard, \
	t_d_list *next);
t_d_list_header	*ft_d_list_header_add_tail(t_d_list_header *standard, \
	t_d_list *prev);

t_d_list		*ft_d_list_header_pop_head(t_d_list_header *standard);
t_d_list		*ft_d_list_header_pop_tail(t_d_list_header *standard);

#endif