/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:01:31 by arbocqui          #+#    #+#             */
/*   Updated: 2018/12/04 15:38:28 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*new;

	start = 0;
	new = NULL;
	if (s)
	{
		end = ft_strlen(s) - 1;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		end += 2;
		if (s[start] == '\0')
			return (new = ft_strdup(s + start));
		return (new = ft_strsub(s, start, end - start - 1));
	}
	return (new);
}
