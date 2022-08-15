/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:29:07 by lrosch            #+#    #+#             */
/*   Updated: 2021/07/01 15:44:08 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	int		b;
	char	*result;

	b = 0;
	i = 0;
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	result = malloc(j + k + 1);
	if (result == 0)
		return (result);
	while (i < j)
	{
		result[i] = s1[i];
		i++;
	}
	while (i <= j + k)
	{
		result[i] = s2[b];
		i++;
		b++;
	}
	return (result);
}
