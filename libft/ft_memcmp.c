/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 04:09:14 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/08 04:40:54 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*t1;
	const unsigned char	*t2;

	i = 0;
	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return ((int)(t1[i] - t2[i]));
		i++;
	}
	return (0);
}
