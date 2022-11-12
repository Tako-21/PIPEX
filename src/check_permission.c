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

void	check_bin_permission(int argc, char **argv, char **env, t_data *data, int index)
{
	data->bin_args = ft_split(argv[index], ' ');
	data->bin = get_bin(argv[index]);
	data->path = get_path(env);
	if (access(argv[1], F_OK) == -1)
		return (exit_error(ERR_EXIST));
	while (*data->path)
	{
		data->bin_path = ft_strjoin(*data->path, data->bin);
		if (!access(data->bin_path, X_OK))
			break ;
		data->path++;
	}
	if (access(data->bin_path, X_OK == -1))
		exit_error(ERR_EXE);
	check_file_permission(argc, argv, env, data);
}

void	check_file_permission(int argc, char **argv, char **env, t_data *data)
{
	data->fd[0] = open(argv[1], O_RDONLY);
	data->fd[1] = open(argv[argc -1], O_RDONLY);
	if (data->fd[0] == -1 || data->fd[1] == -1)
		exit_error(ERR_OPEN);
}