/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:26:11 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/24 14:40:52 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int nbr)
{
	t_stack	*newelement;

	newelement = malloc(sizeof(t_stack));
	if (newelement == NULL)
		return (NULL);
	newelement->num = nbr;
	newelement->next = NULL;
	return (newelement);
}

t_stack	*lstlast(t_stack *lst)
{
	t_stack	*end;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			end = lst;
		}
		lst = lst->next;
	}
	return (end);
}

int	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*end;

	if (new == NULL)
		return (0);
	if (!*lst)
		*lst = new;
	else
	{
		end = lstlast(*lst);
		end->next = new;
	}
	return (1);
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
