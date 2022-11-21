/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:01:05 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/10 02:15:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_str(int c, char const *str)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtn;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_char_in_str(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
	{
		rtn = ft_strdup("");
		if (!rtn)
			return (0);
		else
			return (rtn);
	}
	while (ft_char_in_str(s1[end - 1], set))
		end--;
	rtn = ft_substr(s1, start, end - start);
	return (rtn);
}
