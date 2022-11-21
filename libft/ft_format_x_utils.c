/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:54:06 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:28 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_xcheck_hash(char *nbr, t_print *tab, const char *prefix, int f)
{
	char	*rtn;

	if (!tab->hash)
		return (nbr);
	if (nbr && *nbr == '0' && ft_strlen(nbr) == 1 && f)
		return (nbr);
	rtn = ft_strjoin(prefix, nbr);
	return (free(nbr), rtn);
}

char	*ft_xcheck_point(char *nbr, t_print *tab, const char *prefix, int f)
{
	char	*rtn;
	size_t	nlen;

	if (!tab->point || !nbr)
		return (nbr);
	if (*nbr == '0' && ft_strlen(nbr) == 1 && f)
	{
		free(nbr);
		nbr = ft_strdup("");
		if (!nbr)
			return (NULL);
	}
	if (*nbr && (nbr[1] == 'x' || nbr[1] == 'X'))
	{
		nlen = ft_strlen(nbr + 2);
		rtn = (char *)ft_calloc((nlen + 1), sizeof(char));
		if (!rtn)
			return (free(nbr), NULL);
		ft_strlcpy(rtn, (nbr + 2), nlen + 1);
		rtn = ft_zerospaces_s(rtn, '0', tab->p_num - 2);
		rtn = ft_xcheck_hash(rtn, tab, prefix, 0);
		return (free(nbr), rtn);
	}
	return (rtn = ft_zerospaces_s(nbr, '0', tab->p_num), rtn);
}

char	*ft_format_x_usingflags(char *nbr, t_print *tab, const char *prefix,
		int f)
{
	nbr = ft_xcheck_hash(nbr, tab, prefix, f);
	if (nbr && (nbr[1] == 'x' || nbr[1] == 'X') && f)
		tab->p_num += 2;
	nbr = ft_xcheck_point(nbr, tab, prefix, f);
	if (nbr && tab->mines)
		nbr = ft_mins_s(nbr, tab);
	else if (nbr && tab->zero && !tab->point)
	{
		tab->point = 1;
		tab->p_num = tab->w_nbr;
		nbr = ft_xcheck_point(nbr, tab, prefix, 0);
	}
	else if (nbr && tab->width)
		nbr = ft_zerospaces_s(nbr, 32, tab->w_nbr);
	return (nbr);
}
