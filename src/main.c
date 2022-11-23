/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/23 20:01:54 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "tools.h"
#include "utils.h"
#include "get.h"
#include "error.h"
#include "exec.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

static void	init_pfds(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_pipes)
	{
		if (pipe(data->pfd + i * 2) == -1)
			exit_error(ERR_PIPE);
	}
}

void	pipex(t_data *data)
{
	int	pid;
	int	status;

	init_pfds(data);
	exe_firstbin(data);
	if (data->args.argc == 5
		|| (data->index_firstbin == 3 && data->args.argc == 6))
		{
			// return ;
			return (exe_lastbin(data));
		}
	while (data->index_firstbin < data->args.argc - 2)
	{
		check_bin_permission(data, data->index_firstbin);
		pid = fork();
		if (pid < 0)
			exit_error(ERR_FORK);
		else if (pid == 0)
			exe_bin(data, data->read, data->write);
		data->read += 2;
		data->write += 2;
		printf("index first bin : %d\n", data->index_firstbin);
		freemem(data);
		data->index_firstbin++;
	}
	exe_lastbin(data);
	wait(&status);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init(argc, argv, env, &data);
	pipex(&data);
	close_fd(&data);
	return (21);
}
