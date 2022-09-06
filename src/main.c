/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/06 19:46:45 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "utils.h"
#include "get_path.h"
#include "get_cmd.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int	exit_error(int sig_err)
{
	const char	*map_error[ERR__LENGHT] = {
		"Error while opening file\n",
		"Too few arguments.\n",
		"Too many arguments.\n"
	};

	ft_putstr_fd((char *)map_error[sig_err], STDERR_FILENO);
	return (-1);
}

// const char *truc_open(void) {
// 	return NULL;
// 	return ERR_OPEN;
// 	ft_putstr_fd(ERR_OPEN)
// }

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	fd_out;

	// if (argc > 5)
	// 	return (exit_error(ERR_ARG_HIGH));
	// else if (argc < 5)
	// 	return (exit_error(ERR_ARG_LOW));
	// fd_in = open(argv[1], O_RDONLY);
	// fd_out = open(argv[4], O_RDONLY);
	// if ((fd_in == -1) || (fd_out == -1))
	// 	return (exit_error(ERR_OPEN));
	get_path(env);
	printf("command : %s \n", get_cmd(argv[2]));
	// char	*const env[] = {"NAME=MOMO", NULL};
	// execve(argv[2], args, env);
	// perror("execve");
	// printf("err : %s\n", strerror(errno));

	// execve: errno str
	return (21);
}
