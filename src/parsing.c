/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:44:23 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/19 13:30:50 by mmeguedm         ###   ########.fr       */
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

t_bool	is_args(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i] == ' ')
		i++;
	while (argv[i] && argv[i] != ' ')
		i++;
	while (argv[i] && argv[i] == ' ')
		i++;
	if (argv[i] == '\0')
		return (FALSE);
	return (TRUE);
}

#include <stdio.h>

void	parse_args(t_data *data, char **argv, int index)
{
	data->bin = get_bin(data->args.argv[index]);
	// data->path = get_path(data->args.env);
	// data->bin_path = NULL;
	if (!is_args(data->args.argv[index]))
	{
		printf("no_args\n");
		data->bin_args = malloc(sizeof(char *) * 2);
		data->bin_args[0] = ft_strdup(data->bin);
		data->bin_args[1] = NULL;
	}
	// while ((*data->args.argv[index]) && (*data->args.argv[index]) != ' ')
	// {
	// 	printf("data->args.argv[%d] : %s\n", index, data->args.argv[index]);
	// 	(data->args.argv[index])++;
	// }
	// if ((*data->args.argv[index]) == '\0')
	// 	data->bin_args = ft_split(data->args.argv[index], ' ');
	// printf("argv[%d] : %s\n", index, argv[index]);
	// printf("data->args.argv[%d] : |%s|\n", index, data->args.argv[index]);
	// if (!data->bin_args || !data->bin || !data->path)
	// 	return (freemem(data), exit_error(ERR_MEM));
}
