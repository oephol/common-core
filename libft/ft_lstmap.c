/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:58:41 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/26 14:14:43 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_node(void *(*f)(void *),\
								void (*del)(void *), void *original_content)
{
	t_list	*new_list;
	void	*new_content;

	new_content = f(original_content);
	new_list = ft_lstnew(new_content);
	if (!new_list)
	{
		del(new_content);
		return (NULL);
	}
	return (new_list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (!lst || !del || !f)
		return (NULL);
	head = ft_create_node(f, del, lst->content);
	if (!head)
		return (NULL);
	temp = head;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_create_node(f, del, lst->content);
		if (!(temp->next))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (head);
}
