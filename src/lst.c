/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:56 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/17 17:44:18 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "tools.h"
#include <stdlib.h>

void	mcollect(t_collector **lst, void	*addr_malloc)
{
	t_collector	*new;

	new = malloc(sizeof(t_collector));
	if (!new)
		return ;
	new->collect = addr_malloc;
	new->next = *lst;
	*lst = new;
}

int	lstsize(t_collector *st)
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

void	lstfree(t_collector **lst)
{
	t_collector	*tmp;

	tmp = (*lst);
	while (tmp)
	{
		(*lst) = (*lst)->next;
		free(tmp->collect);
		free(tmp);
		tmp = (*lst);
	}
}
