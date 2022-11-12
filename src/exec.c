/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:35:09 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/12 13:17:47 by mmeguedm         ###   ########.fr       */
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
	else if (pid == 0)
	{
		close(data->pfd[0]);
		dup2(data->pfd[1], 1);
		close(data->pfd[1]);
		if (execve(bin_path, bin_args, env) == -1)
			exit_error(ERR_EXE);
	}
}

void	std_binin(char *bin_path, char **bin_args, char **env, t_data *data)
{
	close(data->pfd[1]);
	dup2(data->pfd[0], 0);
	close(data->pfd[0]);
	if (execve(bin_path, bin_args, env) == -1)
		exit_error(ERR_EXE);
}