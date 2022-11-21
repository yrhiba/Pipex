/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:51:50 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/12 01:37:13 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned long long	ft_rtn(unsigned long long nbr, int isneg,
		unsigned long long maxll)
{
	if (nbr > (maxll + 1) && isneg)
		return (0);
	else if (nbr > maxll && !isneg)
		return (-1);
	if (isneg)
		return (-nbr);
	return (nbr);
}

int	ft_atoi(const char *str)
{
	long				i;
	unsigned long long	nbr;
	int					isneg;
	unsigned long long	maxll;

	maxll = 9223372036854775806;
	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isneg = 1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
		nbr = (nbr * 10) + (str[i++] - '0');
	nbr = ft_rtn(nbr, isneg, maxll);
	return (nbr);
}
