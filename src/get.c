/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:37:19 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/26 18:28:49 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
#include "tools.h"
#include "error.h"
#include "utils.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


#include <stdio.h>


char	*get_bin(char *cmd)
{
	char	*bin;
	int		len;

	len = 0;
	while (cmd[len] && cmd[len] != ' ')
		len++;
	bin = malloc(sizeof(char) * (len + 1));
	// CHECK MEM LEAKS BELOW
	if (!cmd)
		exit_error(ERR_MEM);
	len = 0;
	while (cmd[len] && cmd[len] != ' ')
	{
		bin[len] = cmd[len];
		len++;
	}
	bin[len] = '\0';
	return (bin);
}

char	**get_path(char	*env[])
{
	char	*path;

	path = ft_strnchr(*env, "PATH", 5);
	while (*env && !path)
	{
		path = ft_strnchr(*env, "PATH=/", 6);
		env++;
	}
	return (ft_split(path, ':'));
}

char	*get_bin_path(char *cmd, char *bin, char **path)
{
	char	*bin_path;
	int	i;

	i = 0;
	if (!access(cmd, X_OK))
		return (ft_strdup(bin));
	while (path[i])
	{
		bin_path = ft_strjoin_path(path[i], bin);
		// CHECK MEM_LEAKS BELOW
		if (!bin_path)
			return (exit_error(ERR_MEM), NULL);
		if (!access(bin_path, X_OK))
			break ;
		free(bin_path);
		bin_path = NULL;
		i++;
	}
	if (access(bin_path, X_OK == -1))
		return (NULL);
	return (bin_path);
}

char	**get_bin_args(char *cmd, char *bin)
{
	char	**bin_args;
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i] == '\0')
	{
		bin_args = malloc(sizeof(char *) * 2);
		bin_args[0] = ft_strdup(bin);
		bin_args[1] = NULL;
	}
	else if (cmd[i] == '-')
		bin_args = ft_split(cmd, ' ');
	else
	{
		bin_args = malloc(sizeof(char *) * 3);
		bin_args[0] = ft_strdup(bin);
		bin_args[1] = ft_strdup(&cmd[i]);
		bin_args[2] = NULL;
	}
	return (bin_args);
}
