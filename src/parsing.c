/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:44:23 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/14 17:56:14 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "tools.h"
#include "utils.h"
#include <stdlib.h>
#include "get.h"

void	check_requirement(t_data *data)
{
	int	i;

	i = 0;
	if (data->args.argc != 5)
		exit_error(ERR_ARG);
	if (!data->args.env || !*data->args.env)
		exit_error(ERR_ENV);
	while (data->args.env[i])
	{
		if (ft_strnchr(data->args.env[i], "PATH", 4) != NULL)
			break ;
		i++;
	}
	if (data->args.env[i] == NULL)
		exit_error(ERR_PATH);
}

void	parse_args(t_data *data, int index)
{
	data->bin_args = ft_split(data->args.argv[index], ' ');
	data->bin = get_bin(data->args.argv[index]);
	data->path = get_path(data->args.env);
	data->bin_path = NULL;
	if (!data->bin_args || !data->bin || !data->path)
		return (freemem(data->args.argc, data), exit_error(ERR_MEM));
}