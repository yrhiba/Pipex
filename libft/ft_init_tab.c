/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:45:37 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:42 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_tab(t_print *tab)
{
	tab->error = 0;
	tab->width = 0;
	tab->mines = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->hash = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->w_nbr = 0;
	tab->p_num = 0;
}
