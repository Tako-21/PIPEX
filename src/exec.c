/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:35:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 16:33:11 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void	exe_binin(t_data *data)
{
	uint8_t	pid;
	int		status;

	if (pipe(data->pfd) == -1)
		exit_error(ERR_PIPE);
	pid = fork();
	if (pid < 0)
		exit_error(ERR_FORK);
	else if (pid == 0)
	{
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->pfd[1], STDOUT_FILENO);
		close(data->pfd[0]);
		close(data->pfd[1]);
		close(data->fd[0]);
		close(data->fd[1]);
		if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
			exit_error(ERR_EXE);
		printf("error\n");
	}
	// else
	// 	wait(&status);
}

void	exe_binout(t_data *data)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
		exit_error(ERR_FORK);
	else if (pid == 0)
	{
		dup2(data->pfd[0], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->pfd[1]);
		close(data->pfd[0]);
		close(data->fd[0]);
		close(data->fd[1]);
		if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
			exit_error(ERR_EXE);
		printf("error\n");
	}
}

void	exe_bin(t_data *data)
{
	int		pid;
	int		status;
	char	read_side[100];

	pid = fork();
	if (pid < 0)
		exit_error(ERR_FORK);
	if (pid == 0)
	{
		read(data->pfd[0], read_side, 100);
		printf("read_side : %s\n", read_side);
		dup2(data->pfd[0], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->pfd[0]);
		close(data->pfd[0]);
		close(data->fd[0]);
		close(data->fd[1]);
		if (execve(data->bin_path, data->bin_args, data->args.env) == -1)
			exit_error(ERR_EXE);
	}
	else
	{
		close(data->pfd[0]);
		close(data->pfd[1]);
		wait(&status);
	}
}
