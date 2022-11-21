/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:20:26 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:25:50 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_format(const char *format, int i, t_print *tab)
{
	if (format[i] == 'c')
		ft_format_c(tab, va_arg(tab->args, int));
	else if (format[i] == 's')
		ft_format_s(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_format_d(tab);
	else if (format[i] == '%')
		ft_format_c(tab, '%');
	else if (format[i] == 'u')
		ft_format_u(tab);
	else if (format[i] == 'x')
		ft_format_x(tab, LWHEX, LWPRX);
	else if (format[i] == 'X')
		ft_format_x(tab, UPHEX, UPPRX);
	else if (format[i] == 'p')
		ft_format_p(tab);
	else
		ft_format_c(tab, format[i]);
	return (i);
}
