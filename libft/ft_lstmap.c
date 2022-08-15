/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:23:47 by lrosch            #+#    #+#             */
/*   Updated: 2021/07/14 16:38:30 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*start;
	t_list	*element;
	int		len;

	len = ft_lstsize(lst);
	start = lst;
	newlst = (t_list *)malloc(sizeof(t_list *) * len);
	if (!newlst)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		element = ft_lstnew((t_list *)f((t_list *)lst->content));
		if (!element)
			ft_lstclear(&start, del);
		else
			ft_lstadd_back(&newlst, element);
		lst = lst->next;
	}
	return (newlst);
}
