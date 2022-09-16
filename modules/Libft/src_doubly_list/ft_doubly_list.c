/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:46:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 21:48:55 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <libft.h>

t_d_list	*ft_d_list_new(void *data)
{
	t_d_list	*new;

	if (!ft_zeromalloc((void **)&new, sizeof(t_d_list)))
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_d_list	*ft_d_list_del(t_d_list *lst, void (*del)(void *))
{
	t_d_list	*lst_life;

	lst_life = NULL;
	if (lst == NULL || del == NULL)
		return (NULL);
	if (lst->prev && ft_ptrcpy((void **)&lst_life, lst->prev))
		lst->prev->next = lst->next;
	if (lst->next && ft_ptrcpy((void **)&lst_life, lst->next))
		lst->next->prev = lst->prev;
	del(lst->data);
	free(lst);
	return (lst_life);
}

t_d_list	*ft_d_list_free(t_d_list **lst, void (*del)(void *))
{
	t_d_list	*lst_life;

	lst_life = NULL;
	if (lst == NULL)
		return (NULL);
	lst_life = *lst;
	while (lst_life)
		lst_life = ft_d_list_del(lst_life, del);
	*lst = NULL;
	return (lst_life);
}

t_d_list_header	*ft_d_list_header_free(t_d_list_header **lst_header, \
	void (*del)(void *))
{
	ft_d_list_free(&(*lst_header)->head, del);
	*lst_header = NULL;
	return (NULL);
}

t_d_list_header	*ft_d_list_header_init(t_d_list *lst)
{
	t_d_list_header	*new;

	if (!ft_zeromalloc((void **)&new, sizeof(t_d_list_header)))
		return (NULL);
	new->head = lst;
	while (lst && lst->next)
		lst = lst->next;
	new->tail = lst;
	return (new);
}
