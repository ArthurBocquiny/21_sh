/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:07:09 by arbocqui          #+#    #+#             */
/*   Updated: 2018/12/06 15:10:17 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_nul(const char *s1, const char *s2)
{
	if (!*s1 && *s2)
		return ((char*)s2);
	else if (*s1 && !*s2)
		return ((char*)s1);
	return (ft_strjoin(s1, s2));
}
