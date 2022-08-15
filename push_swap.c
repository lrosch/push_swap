/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:37:15 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/24 14:58:17 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split(char **argv, int i)
{
	int		*arr;
	char	**split;
	t_stack	*A;

	A = NULL;
	if (ft_empty(argv[1]))
		return ;
	split = ft_split(argv[1], ' ');
	if (split == NULL)
		return ;
	error_checking_split(ft_element_nbr(split) + 1, split);
	arr = ft_assign_split(ft_element_nbr(split) + 1, split);
	while (i < ft_element_nbr(split))
	{
		if (!lstadd_back(&A, lstnew(arr[i])))
			ft_freeall(A, arr, split);
		i++;
	}
	ft_navigate(&A, ft_element_nbr(split) + 1, arr, split);
}

void	non_split(int argc, char **argv)
{
	int		i;
	int		*arr;
	t_stack	*A;

	i = 0;
	A = NULL;
	error_checking(argc, argv);
	arr = ft_assign(argc, argv);
	i = 0;
	while (i < argc - 1)
	{
		if (!lstadd_back(&A, lstnew(arr[i])))
			ft_freeall(A, arr, NULL);
		i++;
	}
	ft_navigate(&A, argc, arr, NULL);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
		exit(0);
	if (argc == 2)
	{
		split(argv, i);
	}
	else
	{
		non_split(argc, argv);
	}
	return (0);
}
