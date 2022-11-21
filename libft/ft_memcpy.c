/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:13:27 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/08 15:46:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*ssrc;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dest = (char *)dst;
	ssrc = (const char *)src;
	while (n--)
		dest[n] = ssrc[n];
	return (dst);
}
