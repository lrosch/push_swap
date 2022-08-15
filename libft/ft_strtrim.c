/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:02:02 by lrosch            #+#    #+#             */
/*   Updated: 2021/07/01 19:15:14 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_allocate(const char *s1, const char *set)
{
	int		i;
	int		j;
	char	*str;

	j = (ft_strlen(s1) - 1);
	i = 0;
	while (ft_check(s1[i], set) == 1 && s1[i] != '\0')
		i++;
	while (ft_check(s1[j], set) == 1 && j > i)
		j--;
	str = malloc(j - i + 2);
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	j = (ft_strlen(s1) - 1);
	i = 0;
	k = 0;
	str = (ft_allocate(s1, set));
	while (ft_check(s1[i], set) == 1 && s1[i] != '\0')
	{
		i++;
	}
	while (ft_check(s1[j], set) == 1 && j > i)
	{
		j--;
	}
	while (i <= j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
