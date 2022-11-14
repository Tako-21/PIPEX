/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/14 17:56:14 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "utils.h"
#include "get.h"
#include "error.h"
#include "exec.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

// Gerer le chemin absolu
// Gerer avec meme nom de fichier que nom de commande.

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	data.args.argc = argc;
	data.args.argv = argv;
	data.args.env = env;
	check_requirement(&data);
	check_file_permission(&data);
	check_bin_permission(&data, 2);
	std_binout(data.bin_path, data.bin_args, env, &data);
	freemem(argc, &data);
	check_bin_permission(&data, 3);
	std_binin(data.bin_path, data.bin_args, env, &data);

	// printf("command	: %s \n", get_bin(argv[2]));
	// printf("path 	: %s \n", get_path(argv[2]));
	// perror("execve");
	// printf("err : %s\n", strerror(errno));
	// freemem(argc, &data);
	return (21);
}
