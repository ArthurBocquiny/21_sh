/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:40:06 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/13 20:54:04 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)str1)[i] == ((unsigned char*)str2)[i] && i < n)
			i++;
		else
			return (((unsigned char*)str1)[i] - ((unsigned char*)str2)[i]);
	}
	return (0);
}
