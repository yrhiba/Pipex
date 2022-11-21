/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:47:55 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/12 01:43:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (*str)
	{
		if (*str != c && f == 0)
		{
			f = 1;
			i++;
		}
		else if (*str == c)
			f = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **rtn)
{
	size_t	i;

	i = 0;
	while (rtn[i])
	{
		free(rtn[i]);
		i++;
	}
	free(rtn);
	rtn = 0;
}

static char	**ft_doit(char **rtn, const char *s, size_t slen, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = -1;
	j = 0;
	index = -1;
	while (++i <= slen)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == slen) && index >= 0)
		{
			rtn[j] = word_dup(s, index, i);
			if (!rtn[j])
			{
				ft_free(rtn);
				return (NULL);
			}
			j++;
			index = -1;
		}
	}
	rtn[j] = 0;
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	size_t	slen;
	char	**rtn;

	if (!s)
		return (0);
	rtn = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!rtn)
		return (0);
	slen = ft_strlen(s);
	rtn = ft_doit(rtn, s, slen, c);
	return (rtn);
}
