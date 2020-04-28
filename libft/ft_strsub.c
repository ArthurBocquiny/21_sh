/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:28:21 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/14 16:45:20 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*troncon;

	i = 0;
	troncon = NULL;
	if (s)
	{
		if (!(troncon = ft_strnew(len)))
			return (0);
		while (i < len)
		{
			troncon[i] = s[start];
			i++;
			start++;
		}
		troncon[i] = '\0';
	}
	return (troncon);
}
