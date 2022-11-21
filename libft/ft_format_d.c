/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:38:18 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:05 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_format_d_pluspace(char *nbr, int c)
{
	char	*rtn;
	size_t	size;
	size_t	i;

	if (nbr[0] == '-')
		return (nbr);
	size = ft_strlen(nbr) + 2;
	rtn = (char *)malloc(sizeof(char) * size);
	if (!rtn)
		return (free(nbr), NULL);
	i = 0;
	rtn[i] = c;
	while (++i < size - 1)
		rtn[i] = nbr[i - 1];
	return (rtn[i] = '\0', free(nbr), rtn);
}

char	*ft_format_d_precision(char *nbr, int len, int c, int f)
{
	char	*rtn;
	char	*tmp;
	size_t	i[3];

	i[2] = ft_strlen(nbr);
	if (len < (int)i[2])
		return (nbr);
	rtn = (char *)malloc(sizeof(char *) * (len + 1));
	if (!rtn)
		return (free(nbr), NULL);
	tmp = rtn;
	i[1] = 0;
	if ((nbr[i[1]] == '-' || nbr[i[1]] == '+' || nbr[i[1]] == 32) && c == '0')
	{
		if (nbr[i[1]] == '-' && f)
			i[2] -= 1;
		*tmp++ = nbr[i[1]++];
	}
	i[0] = -1;
	while (++i[0] < (size_t)(len - (int)i[2]))
		*tmp++ = c;
	while (nbr[i[1]])
		*tmp++ = nbr[i[1]++];
	return (*tmp = '\0', free(nbr), rtn);
}

char	*ft_format_d_usingflags(char *nbr, t_print *tab)
{
	if (tab->point)
	{
		if (*nbr == '0' && ft_strlen(nbr) == 1)
		{
			free(nbr);
			nbr = ft_strdup("");
		}
		if (nbr)
			nbr = ft_format_d_precision(nbr, tab->p_num, '0', 1);
	}
	if (nbr && tab->plus)
		nbr = ft_format_d_pluspace(nbr, '+');
	else if (nbr && tab->space)
		nbr = ft_format_d_pluspace(nbr, 32);
	if (nbr && tab->mines)
		nbr = ft_mins_s(nbr, tab);
	else if (nbr && tab->zero && !tab->point)
		nbr = ft_format_d_precision(nbr, tab->w_nbr, '0', 0);
	else if (nbr && tab->width)
		nbr = ft_format_d_precision(nbr, tab->w_nbr, 32, 0);
	return (nbr);
}

int	ft_format_d(t_print *tab)
{
	char	*nbr;
	int		n;

	n = va_arg(tab->args, int);
	nbr = ft_itoa(n);
	if (!nbr)
		return (tab->error = 1, -1);
	nbr = ft_format_d_usingflags(nbr, tab);
	if (!nbr)
		return (tab->error = 1, -1);
	ft_addstr((const char *)nbr, tab);
	return (free(nbr), 0);
}
