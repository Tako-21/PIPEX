/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:03:21 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 19:04:02 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>
#include <unistd.h>

void	freemem(t_data *data)
{
	int	i;

	i = -1;
	if (data->bin)
		free(data->bin);
	if (data->bin_path)
		free(data->bin_path);
	while (data->path && data->path[++i])
		free(data->path[i]);
	if (data->path)
		free(data->path);
	i = -1;
	while (data->bin_args && data->bin_args[++i] != NULL)
		free(data->bin_args[i]);
	if (data->bin_args)
		free(data->bin_args);
}

void	close_fd(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_pipes * 2)
		close(data->pfd[i]);
	close(data->fd[0]);
	close(data->fd[1]);
}
