/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:53:16 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/28 17:12:18 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "get.h"
#include "error.h"
#include <stdlib.h>

void	init_list(t_dblist *lst)
{
	lst->first = NULL;
	lst->last = NULL;
}


void add_node_front(t_dblist *l, int val)
{
	t_storage_cmd *new;

	new = malloc(sizeof(*new));
	if(!new)
		exit(EXIT_FAILURE);
	new->pos = val;
	new->next = l->first;
	new->prev = NULL;
	if(l->first)
		l->first->prev = new;
	else
		l->last = new;
	l->first = new;
}

void	add_node_back(t_dblist *l, char *cmd, char *env[])
{
	t_storage_cmd	*new;
	static int		pos = 1;

	new = malloc(sizeof(*new));
	if (!new)
		exit_error(ERR_MEM);
	new->pos = pos;
	new->prev = l->last;
	new->next = NULL;
	new->bin = get_bin(cmd);
	new->path = get_path(env);
	new->bin_args = get_bin_args(cmd, new->bin);
	new->bin_path = get_bin_path(cmd, new->bin, new->path);
	if (l->last)
		l->last->next = new;
	else
		l->first = new;
	l->last = new;
	pos++;
}

void	ft_lstaddback(t_storage_cmd **lst)
{
	t_storage_cmd	*new;
	t_storage_cmd	*tmp;
	static int		pos = 1;


	tmp = (*lst);
	new = malloc(sizeof(*new));
	if (!new)
		exit_error(ERR_MEM);
	new->next = NULL;
	new->pos = pos;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	pos++;
}

void	add_node(t_storage_cmd **storage, char *cmd, char *env[])
{
	t_storage_cmd	*new;
	static int		pos = 1;

	new = malloc(sizeof(*new));
	if (!new)
		exit_error(ERR_MEM);
	new->next = (*storage);
	new->bin = get_bin(cmd);
	new->path = get_path(env);
	new->bin_args = get_bin_args(cmd, new->bin);
	new->bin_path = get_bin_path(cmd, new->bin, new->path);
	new->pos = pos;
	*(storage) = new;
	pos++;
}
