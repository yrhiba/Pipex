/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:07:38 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/07 04:26:03 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *) b;
	i = 0;
	while (i < len)
		tmp[i++] = c;
	b = (void *) tmp;
	return (b);
}
