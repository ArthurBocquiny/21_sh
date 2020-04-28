/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:06:21 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/26 18:26:18 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	**ft_malloc_words(char const *str, char **table, char c)
{
	int			i;
	int			nb_words;

	nb_words = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		i++;
		if (str[i] == c || str[i] == '\0')
		{
			nb_words++;
			while (str[i] == c)
				i++;
		}
	}
	if (!(table = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (0);
	table[nb_words] = 0;
	return (table);
}

static	char	**ft_malloc_words_letter(char const *str, char **table, char c)
{
	int			i;
	int			x;
	int			nb_wrd_let;

	nb_wrd_let = 1;
	i = 0;
	x = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		i++;
		if (str[i] == c || str[i] == '\0')
		{
			if (!(table[x] = (char*)malloc(sizeof(char) * (nb_wrd_let + 1))))
				return (0);
			x++;
			nb_wrd_let = 0;
			while (str[i] == c)
				i++;
		}
		nb_wrd_let++;
	}
	return (table);
}

static	char	**ft_concat_string(char const *str, char **table, char c)
{
	int			i;
	int			x;
	int			y;

	y = 0;
	x = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		table[x][y] = str[i];
		y++;
		i++;
		if (str[i] == c || str[i] == '\0')
		{
			table[x][y] = '\0';
			x++;
			y = 0;
			while (str[i] == c)
				i++;
		}
	}
	return (table);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**table;

	table = NULL;
	if (s && c)
	{
		if (!(table = ft_malloc_words(s, table, c)))
			return (NULL);
		if (!(table = ft_malloc_words_letter(s, table, c)))
			return (NULL);
		if (!(table = ft_concat_string(s, table, c)))
			return (NULL);
	}
	return (table);
}
