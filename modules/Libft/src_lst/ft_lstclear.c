/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:19:52 by kyoulee           #+#    #+#             */
/*   Updated: 2022/03/25 19:50:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		lst_temp = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = lst_temp;
	}
	*lst = NULL;
}
