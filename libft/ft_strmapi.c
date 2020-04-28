/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:01:01 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/14 16:07:28 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			new[i] = f(i, s[i]);
			i++;
		}
	}
	return (new);
}
