/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:10:43 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/24 14:50:46 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_checking(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_notint(argv[i]) || !ft_duplicate(argv, i)
			|| ft_atoi_big(argv[i]) > INT_MAX || ft_atoi_big(argv[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	ft_duplicate(char **s, int i)
{
	int	j;
	int	num;

	j = 1;
	num = ft_atoi(s[i]);
	while (j < i)
	{
		if (ft_atoi(s[j]) == num)
			return (0);
		j++;
	}
	return (1);
}

int	ft_notint(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' && !s[i + 1])
		return (0);
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

long long int	ft_atoi_big(const char *str)
{
	long long int	i;
	long long int	res;
	int				vrz;

	i = 0;
	vrz = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			vrz = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (vrz * res);
}
