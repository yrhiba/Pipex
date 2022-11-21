/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:27:20 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/10 02:40:45 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenstr(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	size_t	ft_lcpystr(char *dst, const char *src, size_t dstsize)
{
	size_t	lens;
	size_t	i;

	lens = ft_lenstr(src);
	if (!dst || !src)
		return (0);
	else if (!dstsize)
		return (lens);
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lens);
}

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	size_t	size;

	size = ft_lenstr(s1) + 1;
	rtn = (char *)malloc(sizeof(char) * size);
	if (!rtn)
		return (0);
	ft_lcpystr(rtn, s1, size);
	return (rtn);
}
