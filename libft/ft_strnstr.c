/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:29:29 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/27 00:27:38 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*aiguille)
		return ((char*)meule_de_foin);
	while (meule_de_foin[i] && i < l)
	{
		if (meule_de_foin[i] == aiguille[j])
		{
			while (meule_de_foin[i + j] == aiguille[j] && (i + j) < l)
			{
				j++;
				if (aiguille[j] == '\0')
					return ((char*)&meule_de_foin[i]);
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
