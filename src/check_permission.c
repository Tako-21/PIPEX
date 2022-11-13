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
	int	i;

	i = 0;
	data->bin_args = ft_split(argv[index], ' ');
	data->bin = get_bin(argv[index]);
	data->path = get_path(env);
	data->bin_path = NULL;
	if (!data->bin_args || !data->bin || !data->path)
		return (freemem(argc, data), exit_error(ERR_MEM));
	while (data->path[i])
	{
		data->bin_path = ft_strjoin(data->path[i], data->bin);
		if (!access(data->bin_path, X_OK))
			break ;
		free(data->bin_path);
		data->bin_path = NULL;
		i++;
	}
	if (access(data->bin_path, X_OK == -1))
		exit_error(ERR_EXE);
}

void	check_file_permission(int argc, char **argv, char **env, t_data *data)
{
	if (access(argv[1], F_OK) == -1 || access(argv[argc - 1], F_OK) == -1)
		return (exit_error(ERR_EXIST));
	data->fd[0] = open(argv[1], O_RDONLY);
	data->fd[1] = open(argv[argc -1], O_WRONLY | O_CREAT, S_IRWXU);
	if (data->fd[0] == -1)
		exit_error(ERR_OPEN);
	if (data->fd[1] == -1)
	{
		close(data->fd[0]);
		exit_error(ERR_OPEN);
	}
}
