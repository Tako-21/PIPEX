/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:35:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/19 13:25:04 by mmeguedm         ###   ########.fr       */
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
	int	i;

	i = -1;
	check_bin_permission(data, data->args.argc - 2);
	while (data->bin_args[++i])
		printf("data->bin_args[%d] : %s\n", i, data->bin_args[i]);
	pid = fork();
	if (pid < 0)
		exit_error(ERR_FORK);
	else if (pid == 0)
	{
		dup2(data->pfd[0], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close_fd(data);
		if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
			exit_error(ERR_EXE);
	}
	freemem(data);
}

void	exe_bin(t_data *data)
{
	int	i;

	i = -1;
	printf("data->bin : %s\n", data->bin);
	while (data->bin_args[++i])
		printf("data->bin_args : %s\n", data->bin_args[i]);
	dup2(data->pfd[0], STDIN_FILENO);
	dup2(data->pfd[3], STDOUT_FILENO);
	close_fd(data);
	if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
		exit_error(ERR_EXE);
}
