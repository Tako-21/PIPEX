/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:44:23 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/22 13:31:45 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "tools.h"
#include "utils.h"
#include <stdlib.h>
#include "get.h"

void	check_path_env(t_data *data)
{
	int	i;

	i = 0;
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

static void	fill_bin_args(t_data *data, int index)
{
	int	i;

	i = 0;
	while (data->args.argv[index][i] && data->args.argv[index][i] == ' ')
		i++;
	while (data->args.argv[index][i] && data->args.argv[index][i] != ' ')
		i++;
	while (data->args.argv[index][i] && data->args.argv[index][i] == ' ')
		i++;
	if (data->args.argv[index][i] == '\0')
	{
		data->bin_args = malloc(sizeof(char *) * 2);
		data->bin_args[0] = ft_strdup(data->bin);
		data->bin_args[1] = NULL;
	}
	else if (data->args.argv[index][i] == '-')
		data->bin_args = ft_split(data->args.argv[index], ' ');
	else
	{
		data->bin_args = malloc(sizeof(char *) * 3);
		data->bin_args[0] = ft_strdup(data->bin);
		data->bin_args[1] = ft_strdup(&data->args.argv[index][i]);
		data->bin_args[2] = NULL;
	}
}


void	parse_args(t_data *data, int index)
{
	data->bin = get_bin(data->args.argv[index]);
	data->path = get_path(data->args.env);
	data->bin_path = NULL;
	fill_bin_args(data, index);
	if (!data->bin_args || !data->bin || !data->path)
		return (freemem(data), exit_error(ERR_MEM));
}
