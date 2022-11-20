/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:34:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/20 11:25:05 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
#include "tools.h"
#include "error.h"
#include <stdlib.h>

void	init(int argc, char **argv, char **env,  t_data *data)
{
	if (argc < 5)
		exit_error(ERR_ARG);
	data->collect = NULL;
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.env = env;
	data->n_pipes = (argc - 4);
	data->pfd = malloc(sizeof(int) * (data->n_pipes * 2));
	check_requirement(data);
	check_file_permission(data);

}
