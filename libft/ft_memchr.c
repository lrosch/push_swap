/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:39:20 by lrosch            #+#    #+#             */
/*   Updated: 2021/06/30 19:12:03 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*strp;

	strp = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (strp[i] == (unsigned char)c)
		{
			return ((unsigned char *)(strp + i));
		}
		i++;
	}
	return (NULL);
}
