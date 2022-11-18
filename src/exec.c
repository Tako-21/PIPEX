/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:35:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 19:17:46 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	uint8_t	pid;
	int		status;

	check_bin_permission(data, 2);
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
	int	pid;
	int	status;

	check_bin_permission(data, data->args.argc - 2);
	pid = fork();
	if (pid < 0)
		exit_error(ERR_FORK);
	else if (pid == 0)
	{
		dup2(data->pfd[2], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close_fd(data);
		if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
			exit_error(ERR_EXE);
	}
	freemem(data);
}

void	exe_bin(t_data *data)
{
	dup2(data->pfd[0], STDIN_FILENO);
	// dup2(data->pfd[3], STDOUT_FILENO);
	close_fd(data);
	if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
		exit_error(ERR_EXE);
}
