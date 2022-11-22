/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:41:49 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/22 13:27:51 by mmeguedm         ###   ########.fr       */
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
	int		line_size;

	data->fd[0] = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	if (data->fd[0] == -1)
		exit_error(ERR_OPEN);
	while (!ft_strcmp(line, data->args.argv[2]))
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		ft_putstr_fd(line ,data->fd[0]);
		ft_putstr_fd("\n" ,data->fd[0]);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
}
