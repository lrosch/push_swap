/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:19:05 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/24 13:08:55 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrofe(char const *str, char c)
{
	int		nbr;
	int		conf;
	int		i;

	nbr = 0;
	conf = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			conf = 1;
		if ((conf == 1 && str[i] == c) || (conf == 1 && str[i + 1] == '\0'))
		{
			nbr++;
			conf = 0;
		}
		i++;
	}
	return (nbr);
}

int	ft_nbrofch(char const *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] != c && s[i] != '\0')
	{
		l++;
		i++;
	}
	return (l);
}

char	**ft_free2d(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (0);
}

char	**ft_write(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = malloc(ft_nbrofch(s, c, i) + 1);
		if (dst[j] == 0)
			return (ft_free2d((char const **)dst, j));
		while (s[i] != '\0' && s[i] != c)
		{
			dst[j][k] = s[i];
			k++;
			i++;
		}
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (s == 0)
		return (0);
	l = ft_nbrofe(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_write(s, dst, c, l));
}
