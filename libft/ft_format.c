/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:38:09 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(const char *format, int i, t_print *tab)
{
	ft_init_tab(tab);
	i = ft_check_format(format, ft_check_flags(format, i + 1, tab),
			tab);
	return (i);
}
