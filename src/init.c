/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:34:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 19:11:53 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
#include "tools.h"
#include "error.h"
#include <stdlib.h>

void	init(int argc, char **argv, char **env,  t_data *data)
{
	data->collect = NULL;
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.env = env;
	// data->n_pipes = 2 * (argc - 4);
	// data->pfd = malloc(sizeof(int) * data->n_pipes);

	check_requirement(data);
	check_file_permission(data);
}
