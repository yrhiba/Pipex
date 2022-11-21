/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:27:20 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 14:39:47 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			slen;
	char			*rtn;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((size_t) start >= slen)
		return (ft_strdup(""));
	if (len > (slen - start))
		len = ft_strlen(s) - start;
	rtn = (char *) malloc (sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		rtn[i] = s[i + start];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
