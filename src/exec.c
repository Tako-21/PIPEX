/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:35:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/23 21:14:09 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "utils.h"

void	exe_firstbin(t_data *data)
{
	int		pid;

	check_bin_permission(data, data->index_firstbin);
	pid = fork();
	if (pid < 0)
		exit_error(ERR_FORK);
	else if (pid == 0)
	{
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->pfd[1], STDOUT_FILENO);
		close_fd(data);
		if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
			exit_error(ERR_EXE);
	}
	freemem(data);
}

void	exe_lastbin(t_data *data)
{
	int				pid;
	uint32_t const	before_last_pfd = (data->n_pipes * 2) - 2;

	check_bin_permission(data, data->args.argc - 2);
	pid = fork();
	if (pid < 0)
		exit_error(ERR_FORK);
	else if (pid == 0)
	{
		dup2(data->pfd[before_last_pfd], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close_fd(data);
		if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
			exit_error(ERR_EXE);
	}
	freemem(data);
}

void	exe_bin(t_data *data, int read, int write)
{
	printf("read : %d\n", read);
	printf("write : %d\n", write);
	dup2(data->pfd[read], STDIN_FILENO);
	dup2(data->pfd[write], STDOUT_FILENO);
	close_fd(data);
	read += 2;
	write += 2;
	if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
		exit_error(ERR_EXE);
}
