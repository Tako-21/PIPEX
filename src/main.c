/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/12/01 19:31:13 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "tools.h"
#include "utils.h"
#include "get.h"
#include "error.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void	init(int argc, char **argv, char **env, t_data *data)
{
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.env = env;
	data->fd_in = 0;
	if (ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
			exit_error(ERR_ARG);
		data->fd[1] = open(argv[argc -1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		data->nb_cmd = argc - 4;
		here_doc(data);
	}
	else
	{
		data->nb_cmd = argc - 3;
		data->fd[0] = open(argv[1], O_RDONLY);
		data->fd[1] = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->fd[0] == -1)
			perror(argv[1]);
	}
	if (data->fd[1] == -1)
	{
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
}

void	do_job(t_data *data, t_storage_cmd *node)
{
	if (!node->bin_path || !node->bin_args)
		cmd_not_found(data, node);
	if (node->pos == 1)
	{
		if (data->fd[0] == -1)
		{
			dup2(data->pfd[1], STDOUT_FILENO);
			return (lstfree(data), close_fds(data), exit(21));
		}
		else
			dup2(data->fd[0], STDIN_FILENO);
	}
	else
		dup2(data->fd_in, STDIN_FILENO);
	if (node ->pos != data->nb_cmd)
		dup2(data->pfd[1], STDOUT_FILENO);
	else
		dup2(data->fd[1], STDOUT_FILENO);
	close_fds(data);
	execve(node->bin_path, node->bin_args, data->args.env);
	return (perror(node->bin), lstfree(data), exit(21));
}

void	launcher(t_data *data)
{
	t_storage_cmd	*tmp;
	pid_t			*pid;
	int				i;

	pid = malloc(sizeof(pid_t) * data->nb_cmd);
	i = 0;
	tmp = data->dblist.first;
	while (tmp)
	{
		if (pipe(data->pfd) == -1)
			exit_error(ERR_PIPE);
		pid[i] = fork();
		if (pid[i] == -1)
			exit_error(ERR_FORK);
		else if (pid[i] == 0)
			do_job(data, tmp);
		else
			extra_launcher(data, i);
		tmp = tmp->next;
		i++;
	}
	while (--i >= 0)
		waitpid(pid[i], NULL, 0);
	free(pid);
}

void	fill_bin(int argc, char **argv, char **env, t_data *data)
{
	int	actual_bin;

	actual_bin = 2;
	if (ft_strcmp(argv[1], "here_doc"))
		actual_bin = 3;
	while (actual_bin < argc - 1)
	{
		add_node_back(&data->dblist, argv[actual_bin], env, data);
		actual_bin++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data		data;

	if (argc < 5)
		exit_error(ERR_ARG);
	init_list(&data);
	init(argc, argv, env, &data);
	fill_bin(argc, argv, env, &data);
	launcher(&data);
	close_fds(&data);
	lstfree(&data);
	return (21);
}
