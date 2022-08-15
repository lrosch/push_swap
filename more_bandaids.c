/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_bandaids.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:13:06 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/30 15:45:00 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate_split(char **s, int i)
{
	int	j;
	int	num;

	j = 0;
	num = ft_atoi(s[i]);
	while (j < i)
	{
		if (ft_atoi(s[j]) == num)
			return (0);
		j++;
	}
	return (1);
}

void	error_checking_split(int argc, char **arr)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!ft_notint(arr[i]) || !ft_duplicate_split(arr, i)
			|| ft_atoi_big(arr[i]) > INT_MAX || ft_atoi_big(arr[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			ft_free_2d(arr);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
