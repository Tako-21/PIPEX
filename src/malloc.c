/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:11:25 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/14 20:12:38 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>

void	ft_lstpush(t_collector **lst, void	*addr_malloc)
{
	t_collector	*new;

	new = malloc(sizeof(t_collector));
	if (!new)
		return ;
	new->collect = addr_malloc;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_collector *st)
{
	int	lenght;

	lenght = 0;
	while (st)
	{
		st = st->next;
		lenght++;
	}
	return (lenght);
}
