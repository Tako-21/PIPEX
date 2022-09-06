/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:37:19 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/06 20:21:00 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmd.h"

char	*get_cmd(char *sh_command)
{
	char	*cmd;
	int		len;

	len = 0;
	while (sh_command[len] && sh_command[len] != ' ')
		len++;
	cmd = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (sh_command[len] && sh_command[len] != ' ')
	{
		cmd[len] = sh_command[len];
		len++;
	}
	return (cmd);
}