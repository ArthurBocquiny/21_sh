/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:20:19 by arbocqui          #+#    #+#             */
/*   Updated: 2018/11/13 15:44:46 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*aiguille)
		return ((char*)meule_de_foin);
	while (meule_de_foin[i] != '\0')
	{
		if (meule_de_foin[i] == aiguille[j])
		{
			while (meule_de_foin[i + j] == aiguille[j])
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
