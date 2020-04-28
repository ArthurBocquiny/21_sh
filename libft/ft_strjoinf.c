/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:29:20 by arbocqui          #+#    #+#             */
/*   Updated: 2019/11/21 11:10:07 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoinf(char *s1, char *s2, int n)
{
	char	*jo;

	jo = ft_strjoin(s1, s2);
	if (n == 1)
		ft_strdel(&s1);
	else if (n == 2)
		ft_strdel(&s2);
	else if (n == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (jo);
}
