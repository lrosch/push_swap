/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bandaids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:14:20 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/24 13:06:57 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_element_nbr(char **array)
{
	int	j;

	j = 0;
	while (array[j])
	{
		j++;
	}
	return (j);
}

int	*ft_assign_split(int argc, char **array)
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
		ft_free_2d(array);
		exit(EXIT_FAILURE);
	}
	return (more_assigning_split(A1, A2, array, argc));
}

int	*more_assigning(int *A1, int *A2, char **array, int argc)
{
	int	i;

	i = 0;
	while (array[i + 1])
	{
		A1[i] = ft_atoi(array[i + 1]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		A2[i] = ft_index(A1, A1[i], argc);
		i++;
	}
	free(A1);
	return (A2);
}

int	*more_assigning_split(int *A1, int *A2, char **array, int argc)
{
	int	i;

	i = 0;
	while (array[i])
	{
		A1[i] = ft_atoi(array[i]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		A2[i] = ft_index(A1, A1[i], argc);
		i++;
	}
	free(A1);
	return (A2);
}

int	ft_empty(char *s)
{
	if (s[0] == '\0')
	{
		return (1);
	}
	else
		return (0);
}
