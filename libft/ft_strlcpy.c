/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:01:41 by lrosch            #+#    #+#             */
/*   Updated: 2021/07/01 14:09:04 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (src == 0)
		return (0);
	src_len = ft_strlen(src);
	if (dest == 0 || src == 0)
		return (0);
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < (size - 1) && size > 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size < src_len)
		dest[size - 1] = '\0';
	else if (size != 0)
		dest[i] = '\0';
	return (src_len);
}
