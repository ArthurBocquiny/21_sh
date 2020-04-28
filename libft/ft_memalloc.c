/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:41:35 by arbocqui          #+#    #+#             */
/*   Updated: 2018/12/04 17:54:16 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*zone;
	size_t	i;

	i = 0;
	zone = NULL;
	if (!(zone = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		zone[i] = 0;
		i++;
	}
	return (zone);
}
