/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:33:14 by arbocqui          #+#    #+#             */
/*   Updated: 2018/12/05 12:58:14 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (alst)
	{
		list = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst)->next = list;
		*alst = NULL;
	}
}
