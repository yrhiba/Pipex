/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:55:25 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/12 01:39:25 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rtn;

	rtn = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			rtn = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (rtn);
}
