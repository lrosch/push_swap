/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:35:07 by lrosch            #+#    #+#             */
/*   Updated: 2021/06/30 18:35:11 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dst;
	if (dst < src)
	{
		while (i < n)
		{
			ptr2[i] = ptr1[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			ptr2[n - 1] = ptr1[n - 1];
			n--;
		}
	}
	return (dst);
}
