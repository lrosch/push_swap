/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:32:19 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/24 14:56:32 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_stack **A, int argc)
{
	t_stack	*B;
	int		i;
	int		j;

	B = NULL;
	i = 0;
	j = 0;
	while (!is_sorted(*A))
	{
		while (i < ft_nbr_of_bits(argc))
		{
			while (j < argc)
			{
				if ((((*A)->num >> i) & 1) == 0)
					B = push(&B, A, 'b');
				else
					rotate(A, 'a');
				j++;
			}
			while (B)
				*A = push(A, &B, 'a');
			i++;
			j = 0;
		}
	}
}

void	ft_sort_small(t_stack **stack, int i)
{
	if (is_sorted(*stack))
		return ;
	if (i == 2)
		swap(*stack, 'a');
	else if (i == 3)
	{
		if (get_position(*stack, get_max(*stack)) == 1)
		{
			rotate(stack, 'a');
			if ((*stack)->num > (*stack)->next->num)
				swap(*stack, 'a');
		}
		else if (get_position(*stack, get_max(*stack)) == 2)
		{
			*stack = rev_rotate(stack, 'a');
			if ((*stack)->num > (*stack)->next->num)
				swap(*stack, 'a');
		}
		else if (get_position(*stack, get_max(*stack)) == 3)
			swap(*stack, 'a');
	}
}

void	ft_sort_smallish(t_stack **A, int i)
{
	t_stack	*B;
	int		min;

	B = NULL;
	if (is_sorted(*A))
		return ;
	while (i >= 4)
	{
		min = get_min(*A);
		if (get_position(*A, min) > i / 2)
		{
			while ((*A)->num != min)
				*A = rev_rotate(A, 'a');
		}
		else
			while ((*A)->num != min)
				rotate(A, 'a');
		i--;
		B = push(&B, A, 'b');
	}
	if (!is_sorted(*A))
		ft_sort_small(A, i);
	while (B)
		*A = push(A, &B, 'a');
}
