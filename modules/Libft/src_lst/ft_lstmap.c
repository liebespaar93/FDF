/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:39:20 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/28 13:57:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *))
{
	t_list	*head_lst;
	t_list	*new_lst;

	head_lst = NULL;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (new_lst == NULL)
		{
			ft_lstclear(&head_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&head_lst, new_lst);
		lst = lst->next;
	}
	return (head_lst);
}
