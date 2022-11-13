/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:35:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/13 15:36:28 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "check_error.h"

void	std_binout(char *bin_path, char **bin_args, char **env, t_data *data)
{
	unsigned int	pid;
	int				w_status;

	if (pipe(data->pfd) == -1)
		exit_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
		exit_error(ERR_FORK);
	// Process ls
	if (pid == 0)
	{
		dup2(data->pfd[1], 1);
		close(data->pfd[0]);
		close(data->pfd[1]);
		close(data->fd[0]);
		close(data->fd[1]);
		if (execve(bin_path, bin_args, env) == -1)
			exit_error(ERR_EXE);
		// execve(bin_path, bin_args, env);
	}
	if (pid > 0)
	{
		printf("child process\n");
	// 	waitpid(-1, &w_status, 0);
	// 	char *const	args_wc[] = {
	// 		"wc",
	// 		"-l",
	// 		NULL
	// 	};
	// 	dup2(data->pfd[0], STDIN_FILENO);
	// 	dup2(data->fd[1], STDOUT_FILENO);
	// 	close(data->pfd[1]);
	// 	close(data->pfd[0]);
	// 	close(data->fd[0]);
	// 	close(data->fd[1]);
	// 	execve("/usr/bin/wc", args_wc, env);
	// // if (execve("/usr/bin/wc", args_wc, env) == -1)
		// printf("error\n");
	// 	// exit_error(ERR_EXE);
	}
	// wait(NULL);
}

void	std_binin(char *bin_path, char **bin_args, char **env, t_data *data)
{
	printf("fd1 : %d\n", data->fd[1]);
	printf("pid : %d\n", getpid());
	char *const	args_wc[] = {
		"wc",
		"-l",
		NULL
	};
	dup2(data->pfd[0], STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->pfd[1]);
	close(data->pfd[0]);
	close(data->fd[0]);
	close(data->fd[1]);
	execve("/usr/bin/wc", args_wc, env);
	// f (execve("/usr/bin/wc", args_wc, env) == -1)
	printf("error\n");
	// // exit_error(ERR_EXE);

}