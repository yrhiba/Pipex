/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:03 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/02 01:26:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;
	size_t	total_size;

	total_size = count * size;
	if (count && (total_size / count) != size)
		return (NULL);
	rtn = malloc(total_size);
	if (!rtn)
		return (NULL);
	ft_bzero(rtn, total_size);
	return (rtn);
}
