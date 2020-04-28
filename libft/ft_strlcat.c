/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:44:12 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/13 15:04:39 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t init_dest;

	init_dest = ft_strlen(dest);
	if (size <= init_dest)
		return (size + ft_strlen(src));
	else
	{
		ft_strncat(dest, src, (size - init_dest - 1));
		return (ft_strlen(src) + init_dest);
	}
}
