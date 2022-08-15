/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:12:13 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/30 22:05:19 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index(int *arr, int num, int argc)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (i < argc - 1)
	{
		if (arr[i] < num)
			j++;
		i++;
	}
	return (j);
}

int	*ft_assign(int argc, char **argv)
{
	int	i;
	int	*A1;
	int	*A2;

	i = 0;
	A1 = (int *)malloc(sizeof(int) * argc - 1);
	A2 = (int *)malloc(sizeof(int) * argc - 1);
	if (A1 == NULL || A2 == NULL)
	{
		if (A1 != NULL)
			free(A1);
		if (A2 != NULL)
			free(A2);
		exit(EXIT_FAILURE);
	}
	return (more_assigning(A1, A2, argv, argc));
}

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack != NULL)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack != NULL)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	get_position(t_stack *stack, int num)
{
	int	pos;

	pos = 1;
	while (stack != NULL)
	{
		if (stack->num == num)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}
