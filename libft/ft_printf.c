/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:46:22 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:27:10 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab || !format)
		return (free(tab), -1);
	tab->buff = (char *)ft_calloc(1, sizeof(char));
	if (!tab->buff)
		return (free(tab), -1);
	tab->buflen = 0;
	va_start(tab->args, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_format(format, i, tab);
		else
			ft_addchar(tab, (char)*(format + i));
		if (tab->error == 1)
			return (free(tab->buff), free(tab), -1);
	}
	i = write(1, tab->buff, tab->buflen);
	return (va_end(tab->args), free(tab->buff), free(tab), i);
}
