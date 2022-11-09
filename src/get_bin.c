/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:37:19 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/24 18:37:09 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
#include <stdlib.h>

char	*get_bin(char *sh_cmd)
{
	char	*cmd;
	int		len;

	len = 0;
	while (sh_cmd[len] && sh_cmd[len] != ' ')
		len++;
	cmd = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (sh_cmd[len] && sh_cmd[len] != ' ')
	{
		cmd[len] = sh_cmd[len];
		len++;
	}
	return (cmd);
}