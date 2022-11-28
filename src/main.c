/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/28 17:15:08 by mmeguedm         ###   ########.fr       */
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
// TO REMOVE ////////////////////////////
void	lstprint(t_storage_cmd *lst)
{
	while (lst)
	{
		printf("lst->bin : %s\n", lst->bin);
		printf("lst->bin_path : %s\n", lst->bin_path);
		printf("pos : %d\n", lst->pos);
		lst = lst->next;
	}
}

// void	lstprint_db(t_data data)
// {
// 	t_storage_cmd	*tmp;

// 	tmp = data.dblist.first;
// 	while (tmp)
// 	{
// 		printf("pos : %s\n", tmp->bin);
// 		// printf("lst->bin : %s\n", lst->bin);
// 		// printf("lst->bin_path : %s\n", lst->bin_path);
// 		// printf("pos : %d\n", lst->pos);
// 		tmp = tmp->next;
// 	}
// }

void	lstprint_db(t_data data)
{
	while (data.dblist.first)
	{
		printf("pos : %d\n", data.dblist.first->pos);
		// printf("lst->bin : %s\n", lst->bin);
		// printf("lst->bin_path : %s\n", lst->bin_path);
		// printf("pos : %d\n", lst->pos);
		data.dblist.first = data.dblist.first->next;
	}
}

/////////////////////////////////////////

void	init(int argc, char **argv, char **env,  t_data *data)
{
	if (argc < 5)
		exit_error(ERR_ARG);
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.env = env;
	data->fd[0] = -2;
	data->fd[1] = -2;
	data->fd_in = 0;
	data->fd[0] = open(data->args.argv[1], O_RDONLY);
	data->fd[1] = open(data->args.argv[data->args.argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data->nb_cmd = argc - 3;
	if (ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
			exit_error(ERR_ARG);
		data->nb_cmd = argc - 4;
		here_doc(data);
	}
}

// void	do_job(t_data *data)
// {
// 	printf("bin : |%s|\n", data->storage->bin);
// 	if (data->storage->pos != data->nb_cmd)
// 		dup2(data->fd_in, STDIN_FILENO);
// 	else
// 		dup2(data->fd[0], STDIN_FILENO);
// 	if (data->storage->pos != 1)
// 		dup2(data->pfd[1], STDOUT_FILENO);
// 	else
// 		dup2(data->fd[1], STDOUT_FILENO);
// 	close(data->pfd[0]);
// 	close(data->pfd[1]);
// 	if (execve(data->storage->bin_path, data->storage->bin_args,
// 		data->args.env) == -1)
// 		exit_error(ERR_EXE);
// }

// void	launcher(t_data *data)
// {
// 	pid_t	pid[data->nb_cmd];
// 	int		i;

// 	i = 0;
// 	while (data->storage)
// 	{
// 		if (pipe(data->pfd) == -1)
// 			exit_error(ERR_PIPE);
// 		pid[i] = fork();
// 		if (pid[i] == -1)
// 			exit_error(ERR_FORK);
// 		else if (pid[i] > 0)
// 			do_job(data);
// 		else
// 		{
// 			close(data->pfd[1]);
// 			if (i != 0)
// 				close(data->fd_in);
// 			if (i != data->nb_cmd)
// 				data->fd_in = data->pfd[0];
// 		}
// 		data->storage = data->storage->next;
// 		i++;
// 	}
// 	while (--i >= 0)
// 		waitpid(pid[i], NULL, 0);
// }


void	fill_bin(int argc, char **argv, char **env, t_data *data)
{
	int	actual_bin;

	actual_bin = 2;
	if (ft_strcmp(argv[1], "here_doc"))
		actual_bin = 3;
	while (actual_bin < argc - 1)
	{
		add_node_back(&data->dblist, argv[actual_bin], env);
		actual_bin++;
	}

}

int	main(int argc, char **argv, char **env)
{
	t_data		data;
	t_dblist	dblist;


	init_list(&dblist);
	// data.storage = NULL;

	// add_node(&data.storage, argv[1], env);
	// add_node(&data.storage, argv[1], env);
	// add_node(&data.storage, argv[1], env);
	// ft_lstaddback(&data.storage);
	// ft_lstaddback(&data.storage);
	// ft_lstaddback(&data.storage);

	// init(argc, argv, env, &data);
	fill_bin(argc, argv, env, &data);
	lstprint_db(data);
	// launcher(&data);
	return (21);
}

// void	freemem(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	if (data->bin)
// 		free(data->bin);
// 	if (data->bin_path)
// 		free(data->bin_path);
// 	while (data->path && data->path[++i])
// 		free(data->path[i]);
// 	if (data->path)
// 		free(data->path);
// 	i = -1;
// 	while (data->bin_args && data->bin_args[++i] != NULL)
// 		free(data->bin_args[i]);
// 	if (data->bin_args)
// 		free(data->bin_args);
// }

// #include <stdio.h>

// void	close_fd(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	// while (++i < data->n_pipes * 2)
// 		// close(data->pfd[i]);
// 	close(data->fd[0]);
// 	close(data->fd[1]);
// 	free(data->pfd);
// 	unlink("tmp");
// }
