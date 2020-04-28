/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:09:06 by arbocqui          #+#    #+#             */
/*   Updated: 2018/12/04 17:55:59 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		count_num(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char	*transform_num(int n)
{
	int		i;
	char	*tab;

	i = 0;
	tab = NULL;
	if (!(tab = (char*)malloc(sizeof(char) * (count_num(n) + 2))))
		return (0);
	if (n == -2147483648)
	{
		tab[0] = '8';
		i++;
		n = 214748364;
	}
	if (n < 0)
		n = -n;
	if (n == 0)
		tab[i++] = '0';
	while (n > 0)
	{
		tab[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static	void	ft_strrev(char *tab)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	i--;
	while (j < i)
	{
		swap = tab[j];
		tab[j] = tab[i];
		tab[i] = swap;
		j++;
		i--;
	}
}

char			*ft_itoa(int n)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = transform_num(n)))
		return (NULL);
	if (n < 0)
	{
		while (tab[i])
			i++;
		tab[i++] = '-';
		tab[i] = '\0';
	}
	ft_strrev(tab);
	return (tab);
}
