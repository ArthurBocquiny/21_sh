/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:40:55 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/27 00:27:00 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	if (s && f)
	{
		if (!(new = ft_strnew(ft_strlen(s))))
			return (0);
		while (s[i])
		{
			new[i] = f(s[i]);
			i++;
		}
	}
	return (new);
}
