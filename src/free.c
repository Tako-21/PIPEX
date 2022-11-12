/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:03:21 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/12 16:56:41 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>
#include <unistd.h>

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	freemem(int argc, t_data *data)
{
	int	i;

	i = 0;
	if (data->bin)
		free(data->bin);

	if (data->bin_path)
		free(data->bin_path);

	while (data->path[i])
	{
		free(data->path[i]);
		i++;
	}

	if (data->path)
		free(data->path);

	i = -1;

	while (data->bin_args[++i] != NULL)
		free(data->bin_args[i]);

	if (data->bin_args)
		free(data->bin_args);

	close(data->fd[0]);
	close(data->fd[1]);
}