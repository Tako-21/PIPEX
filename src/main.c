/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 16:42:08 by mmeguedm         ###   ########.fr       */
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

static void	exe_allbin(t_data *data)
{
	int	i;

	i = 1;
	while (++i < data->args.argc -1)
	{
		printf("argv[%d] : %s\n", i, data->args.argv[i]);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	data.collect = NULL;
	data.args.argc = argc;
	data.args.argv = argv;
	data.args.env = env;
	data.n_pipes = 2 * (argc - 4);

	printf("n.pipes : %d\n", data.n_pipes);
	data.pfd = malloc(sizeof(int) * data.n_pipes);

	check_requirement(&data);
	check_file_permission(&data);

	check_bin_permission(&data, 2);
	exe_binin(&data);
	freemem(&data);

	check_bin_permission(&data, 3);
	exe_binout(&data);
	freemem(&data);

	check_bin_permission(&data, 4);
	exe_bin(&data);
	freemem(&data);
	close_fd(&data);


	return (21);
}
