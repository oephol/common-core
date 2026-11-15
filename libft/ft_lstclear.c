/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:35:38 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/28 14:58:13 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*todel;
	t_list	*temp;

	if (!lst || !del || !*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		todel = temp;
		temp = temp->next;
		del(todel->content);
		free(todel);
	}
	*lst = NULL;
}
