/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:37:19 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 12:15:39 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
#include "tools.h"
#include "utils.h"
#include <stdlib.h>

char	*get_bin(char *sh_cmd)
{
	char	*cmd;
	int		len;

	len = 0;
	while (sh_cmd[len] && sh_cmd[len] != ' ')
		len++;
	cmd = malloc(sizeof(char) * (len + 1));
	if (!cmd)
		return (NULL);
	len = 0;
	while (sh_cmd[len] && sh_cmd[len] != ' ')
	{
		cmd[len] = sh_cmd[len];
		len++;
	}
	cmd[len] = '\0';
	return (cmd);
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
