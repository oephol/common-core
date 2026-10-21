/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:35:38 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/19 12:48:27 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*todel;
	t_list	*temp;

	if (!lst || !del)
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
