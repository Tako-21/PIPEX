/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_permission.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:36:50 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/24 17:18:56 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "get.h"
#include "check_error.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void	check_permission(char **argv, char **env, t_data *data)
{
	int		exe;
	char	*cmd_path;
	char	*cmd_bin;
	char	**cmd_args;

	cmd_args = ft_split(argv[2], ' ');
	cmd_bin = get_cmd(argv[2]);
	exe = 0;
	data->path = get_path(env);
	if (access(argv[1], F_OK) == -1)
		return (exit_error(ERR_EXIST));
	while (*data->path)
	{
		cmd_path = ft_strjoin(*data->path, cmd_bin);
		printf("cmd_path : %s\n", cmd_path);
		if (!access(cmd_path, X_OK))
		{
			exe = 1;
			break ;
		}
		data->path++;
	}
	if (!exe)
		return (exit_error(ERR_EXE));
	data->fd1 = open(argv[1], O_RDONLY);
	// data->fd2 = open(argv[4], O_RDONLY);
	if ((data->fd1 == -1) || (data->fd2 == -1))
		return (exit_error(ERR_OPEN));
	execve(cmd_path, cmd_args, env);
}