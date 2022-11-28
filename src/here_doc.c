/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:41:49 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/28 15:03:29 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include "error.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


void	here_doc(t_data *data)
{
	char	*line;

	line = NULL;
	data->fd[0] = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (data->fd[0] == -1)
		return (exit_error(ERR_OPEN));
	while (!ft_strcmp(line, data->args.argv[2]))
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		free(line);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			exit_error(ERR_MEM);
		if (ft_strcmp(line, data->args.argv[2]))
			break ;
		ft_putstr_fd(line ,data->fd[0]);
		if (!ft_strcmp(line, "\n"))
			ft_putstr_fd("\n" , data->fd[0]);
	}
	free(line);
	close(data->fd[0]);
	data->fd[0] = open(".tmp", O_RDONLY);
	if (data->fd[0] == -1)
		return (exit_error(ERR_OPEN));
}
