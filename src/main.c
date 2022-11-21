/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/21 20:14:12 by mmeguedm         ###   ########.fr       */
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
	int	i;
	int	pid;
	int	status;

	data->read = 0;
	data->write = 3;
	i = 2;
	init_pfds(data);
	exe_firstbin(data);
	if (data->args.argc == 5)
		return (exe_lastbin(data));
	while (++i < data->args.argc - 2)
	{
		check_bin_permission(data, i);
		pid = fork();
		if (pid < 0)
			exit_error(ERR_FORK);
		else if (pid == 0)
			exe_bin(data, data->read, data->write);
		data->read += 2;
		data->write += 2;
	}
	exe_lastbin(data);
	wait(&status);
	freemem(data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init(argc, argv, env, &data);
	// pipex(&data);
	return (21);
}
