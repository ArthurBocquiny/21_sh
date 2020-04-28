/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:51:06 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/13 20:33:09 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = NULL;
	if (str1 > str2)
	{
		while (n > i)
		{
			((char*)str1)[n - 1] = ((char*)str2)[n - 1];
			n--;
		}
		return (str1);
	}
	else
	{
		cpy = ft_memcpy(str1, str2, n);
		return (cpy);
	}
}
