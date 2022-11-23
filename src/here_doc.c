/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:41:49 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/23 21:13:32 by mmeguedm         ###   ########.fr       */
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

	data->fd[0] = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fd[0] == -1)
		return (free(data->pfd), exit_error(ERR_OPEN));
	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	while (!ft_strcmp(line, data->args.argv[2]))
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		ft_putstr_fd(line ,data->fd[0]);
		if (line[0] != '\n')
			ft_putstr_fd("\n" ,data->fd[0]);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(data->fd[0]);
	data->fd[0] = open("tmp", O_RDWR | O_CREAT, 0644);
	if (data->fd[0] == -1)
		return (free(data->pfd), exit_error(ERR_OPEN));
}
