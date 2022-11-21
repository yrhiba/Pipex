/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:10:22 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:14 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_precision_s(char *s, t_print *tab)
{
	int		len;
	int		i;
	char	*rtn;

	len = ft_strlen((const char *)s);
	if (len < tab->p_num)
		return (s);
	rtn = (char *)malloc(sizeof(char) * (tab->p_num + 1));
	if (!rtn)
		return (free(s), NULL);
	i = 0;
	while (i < tab->p_num)
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = '\0';
	return (free(s), rtn);
}

char	*ft_mins_s(char *s, t_print *tab)
{
	char	*rtn;
	int		len;
	int		i;

	len = ft_strlen((const char *)s);
	if (len > tab->w_nbr)
		return (s);
	rtn = (char *)malloc(sizeof(char) * (tab->w_nbr + 1));
	if (!rtn)
		return (free(s), NULL);
	i = 0;
	while (i < len)
	{
		rtn[i] = s[i];
		i++;
	}
	while (i < tab->w_nbr)
		rtn[i++] = 32;
	rtn[i] = '\0';
	return (free(s), rtn);
}

char	*ft_zerospaces_s(char *s, int c, int t_len)
{
	char	*rtn;
	int		len;
	int		i;
	int		j;

	len = (int)ft_strlen((const char *)s);
	if (t_len <= len)
		return (s);
	rtn = (char *)malloc(sizeof(char) * (t_len + 1));
	if (!rtn)
		return (free(s), NULL);
	i = 0;
	while (i < (t_len - len))
		rtn[i++] = c;
	j = 0;
	while (i < t_len)
		rtn[i++] = s[j++];
	rtn[i] = '\0';
	return (free(s), rtn);
}

char	*ft_format_s_usingflags(char *s, t_print *tab)
{
	if (tab->point)
		s = ft_precision_s(s, tab);
	if (s && tab->mines)
		s = ft_mins_s(s, tab);
	else if (s && tab->zero)
		s = ft_zerospaces_s(s, '0', tab->w_nbr);
	else if (s && tab->width)
		s = ft_zerospaces_s(s, 32, tab->w_nbr);
	return (s);
}
