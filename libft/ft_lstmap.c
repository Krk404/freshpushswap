/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:22:20 by jyildiri          #+#    #+#             */
/*   Updated: 2022/01/03 12:58:50 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*newlst;
	t_list	*lstemp;

	(void)del;
	if (lst == NULL)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		if (!newlst)
		{
			lstemp = ft_lstnew((*f)(lst->content));
			newlst = lstemp;
		}
		else
		{
			lstemp->next = ft_lstnew((*f)(lst->content));
			lstemp = lstemp->next;
		}
		lst = lst->next;
	}	
	return (newlst);
}
