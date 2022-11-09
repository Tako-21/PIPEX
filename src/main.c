/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/25 13:33:21 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "utils.h"
#include "get.h"
#include "check_error.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	// parse_args(argc);
	check_bin_permission(argc, argv, env, &data);
	char* arg_list[] = {
	"ls",	/* argv[0], le nom du programme. */
	"-l",
	"/",
	NULL	/* La liste d'arguments doit se terminer par NULL.  */
	};
	// printf("command	: %s \n", get_bin(argv[2]));
	// printf("path 	: %s \n", get_path(argv[2]));
	// perror("execve");
	// printf("err : %s\n", strerror(errno));
	return (21);
}
