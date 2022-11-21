/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:52:35 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:25:56 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_hexlen(unsigned long n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= 16UL;
	}
	return (i);
}

char	*ft_converthex(unsigned long n, const char *base)
{
	char	*rtn;
	size_t	i;

	i = ft_hexlen(n);
	rtn = (char *)ft_calloc((i + 1), sizeof(char));
	if (!rtn)
		return (NULL);
	while (n)
	{
		rtn[--i] = base[n % 16];
		n /= 16UL;
	}
	if (!*rtn)
		*rtn = '0';
	return (rtn);
}
