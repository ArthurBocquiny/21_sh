/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:55:17 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/13 15:30:39 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	while (s_len)
	{
		if (s[s_len] == (char)c)
			return ((char*)&s[s_len]);
		s_len--;
	}
	if (s[0] == (char)c)
		return ((char*)&s[s_len]);
	return (0);
}
