/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:53:46 by lrosch            #+#    #+#             */
/*   Updated: 2021/12/03 14:47:59 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbr_of_bits(int i)
{
	int	j;

	j = 0;
	while (i > 0)
	{
		i = i / 2;
		j++;
	}
	return (j);
}

void	ft_navigate(t_stack **A, int argc, int *arr, char **array)
{
	if (argc <= 4)
		ft_sort_small(A, argc - 1);
	else if (argc <= 6)
		ft_sort_smallish(A, argc - 1);
	else
		ft_sort_big(A, argc - 1);
	ft_freeall(*A, arr, array);
}
