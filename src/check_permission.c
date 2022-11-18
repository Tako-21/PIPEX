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
#include "error.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "exec.h"

#include <sys/wait.h>
#include <stdlib.h>

void	check_bin_permission(t_data *data, int index)
{
	int	i;

	i = 0;
	parse_args(data, index);
	if (!access(data->bin, X_OK))
	{
		data->bin_path = ft_strdup(data->bin	);
		return ;
	}
	while (data->path[i])
	{
		data->bin_path = ft_strjoin(data->path[i], data->bin);
		if (!data->bin_path)
			return (freemem(data), exit_error(ERR_MEM));
		if (!access(data->bin_path, X_OK))
			break ;
		free(data->bin_path);
		data->bin_path = NULL;
		i++;
	}
	if (access(data->bin_path, X_OK == -1))
		exit_error(ERR_EXE);
}

void	check_file_permission(t_data *data)
{
	data->fd[0] = open(data->args.argv[1], O_RDONLY);
	data->fd[1] = open(data->args.argv[data->args.argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd[0] == -1)
		exit_error(ERR_OPEN);
	if (data->fd[1] == -1)
	{
		close(data->fd[0]);
		exit_error(ERR_OPEN);
	}
}
