/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:03:29 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/12 01:41:29 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (!dstsize && !dst)
		return (slen + dstsize);
	dlen = ft_strlen(dst);
	if ((!dstsize || (dstsize <= dlen)))
		return (slen + dstsize);
	i = 0;
	while (src[i] && (i < (dstsize - dlen - 1)))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
