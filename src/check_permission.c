/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bin_permission.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:36:50 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/24 19:52:17 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "get.h"
#include "check_error.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "exec.h"

#include <sys/wait.h>
#include <stdlib.h>

void	check_bin_permission(int argc, char **argv, char **env, t_data *data)
{
	u_int8_t	exe;
	char		**bin_args;
	char		*bin_path;
	char		*bin;

	bin_args = ft_split(argv[2], ' ');
	bin = get_bin(argv[2]);
	exe = 0;
	data->path = get_path(env);
	if (access(argv[1], F_OK) == -1)
		return (exit_error(ERR_EXIST));
	while (*data->path)
	{
		bin_path = ft_strjoin(*data->path, bin);
		if (!access(bin_path, X_OK))
			break ;
		data->path++;
	}
	if (access(bin_path, X_OK == -1))
		exit_error(ERR_EXE);
	if (data->fd[0] == -1)
		exit_error(ERR_OPEN);
	check_file_permission(argc, argv, env, data);
	exec_bin(bin_path, bin_args, env);
}

void	check_file_permission(int argc, char **argv, char **env, t_data *data)
{
	data->fd[0] = open(argv[1], O_RDONLY);
	data->fd[1] = open(argv[argc -1], O_RDONLY);
	if (data->fd[0] == -1 || data->fd[1] == -1)
		exit_error(ERR_OPEN);
}