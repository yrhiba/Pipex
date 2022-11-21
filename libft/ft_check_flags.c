/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:01:47 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:25:45 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip_num(const char *format, int i)
{
	while (format[i] <= '9' && format[i] >= '0')
		i++;
	return (i);
}

int	ft_fcheck_zero(const char *format, int *i, t_print *tab)
{
	if (format[*i] == '0')
	{
		tab->zero = 1;
		*i += 1;
	}
	return (*i);
}

int	ft_fcheck_mins(const char *format, int *i, t_print *tab)
{
	if (format[*i] == '-')
	{
		tab->mines = 1;
		*i += 1;
	}
	return (*i);
}

int	ft_fcheck_point(const char *format, int *i, t_print *tab)
{
	if (format[*i] == '.')
	{
		tab->point = 1;
		*i += 1;
		tab->p_num = ft_miniatoi(format + *i);
		*i = ft_skip_num(format, *i);
	}
	return (*i);
}

int	ft_check_flags(const char *format, int i, t_print *tab)
{
	while (format[i] == '-' || format[i] == '0' || format[i] == '.'
		|| format[i] == '+' || format[i] == 32 || format[i] == '#'
		|| ft_isnum(format[i]))
	{
		ft_fcheck_width(format, &i, tab);
		ft_fcheck_zero(format, &i, tab);
		ft_fcheck_mins(format, &i, tab);
		ft_fcheck_point(format, &i, tab);
		ft_fcheck_hash(format, &i, tab);
		ft_fcheck_space(format, &i, tab);
		ft_fcheck_plus(format, &i, tab);
	}
	return (i);
}
