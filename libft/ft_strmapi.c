/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:55:39 by lrosch            #+#    #+#             */
/*   Updated: 2021/07/06 16:51:31 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*news;

	i = 0;
	if (s == 0)
		return ((char *)s);
	news = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (news == 0)
		return (news);
	while (i < ft_strlen(s))
	{
		news[i] = f(i, s[i]);
		i++;
	}
	return (news);
}
