/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:13:02 by jyildiri          #+#    #+#             */
/*   Updated: 2022/10/21 17:03:10 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nl;

	nl = malloc(sizeof(t_list));
	if (nl == NULL)
		return (NULL);
	nl->content = content;
	nl->next = NULL;
	return (nl);
}
