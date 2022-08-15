/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:29:42 by lrosch            #+#    #+#             */
/*   Updated: 2021/07/14 16:31:33 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptrdst;
	unsigned char		ch;
	const unsigned char	*ptrsrc;

	ch = (unsigned char)c;
	ptrdst = (unsigned char *)dst;
	ptrsrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		if (ptrsrc[i] == ch)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
