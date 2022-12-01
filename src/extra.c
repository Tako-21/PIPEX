/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:26:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/12/01 19:48:51 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "tools.h"
#include <unistd.h>
#include <stdlib.h>

void	extra_launcher(t_data *data, int i)
{
	close(data->pfd[1]);
	if (i != 0)
		close(data->fd_in);
	if (i != data->nb_cmd)
		data->fd_in = data->pfd[0];
}

char	**extra_bin_args(char *cmd, char *bin, int i)
{
	char	**str;

	str = malloc(sizeof(char *) * 3);
	str[0] = ft_strdup(bin);
	str[1] = ft_strdup(&cmd[i]);
	str[2] = NULL;
	return (str);
}

void	extra_list(t_data *l)
{
	l->dblist.first = NULL;
	l->dblist.last = NULL;
}
