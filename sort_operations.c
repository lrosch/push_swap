/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:37:43 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/17 16:47:04 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char letter)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	if (letter == 'a')
		write(1, "sa\n", 3);
	if (letter == 'b')
		write(1, "sb\n", 3);
}

t_stack	*push(t_stack **stack1, t_stack **stack2, char letter)
{
	t_stack	*head;
	int		nbr;

	if (!stack2)
		return (*stack1);
	nbr = (*stack2)->num;
	head = lstnew(nbr);
	head->next = *stack1;
	free(*stack2);
	*stack2 = (*stack2)->next;
	if (letter == 'a')
		write(1, "pa\n", 3);
	if (letter == 'b')
		write(1, "pb\n", 3);
	return (head);
}

void	rotate(t_stack **stack, char letter)
{
	t_stack	*first;
	int		nbr;

	if (!stack || !(*stack)->next)
		return ;
	nbr = (*stack)->num;
	first = lstnew(nbr);
	free(*stack);
	*stack = (*stack)->next;
	lstadd_back(stack, first);
	if (letter == 'a')
		write(1, "ra\n", 3);
	if (letter == 'b')
		write(1, "rb\n", 3);
}

t_stack	*rev_rotate(t_stack **stack, char letter)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->next = *stack;
	while ((*stack)->next->next != NULL)
		*stack = (*stack)->next;
	new->num = (*stack)->next->num;
	free((*stack)->next);
	(*stack)->next = NULL;
	if (letter == 'a')
		write(1, "rra\n", 4);
	if (letter == 'b')
		write(1, "rrb\n", 4);
	return (new);
}
