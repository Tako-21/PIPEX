/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:41:49 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/12/02 16:21:41 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include "error.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

void	nul_character(t_data *data)
{
	ft_putstr_fd("\nwarning: here-document ", STDOUT_FILENO);
	ft_putstr_fd("delimited by end-of-file (wanted ", STDOUT_FILENO);
	ft_putstr_fd(data->args.argv[2], STDOUT_FILENO);
	ft_putstr_fd(")\n", STDOUT_FILENO);
}

void	here_doc(t_data *data)
{
	char	*line;

	line = NULL;
	while (!ft_strcmp(line, data->args.argv[2]))
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		free(line);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (exit_error(ERR_MEM));
		if (!*line)
		{
			nul_character(data);
			break ;
		}
		if (ft_strcmp(line, data->args.argv[2]))
			break ;
		ft_putstr_fd(line, data->pfd[1]);
		if (!ft_strcmp(line, "\n"))
			ft_putstr_fd("\n", data->pfd[1]);
	}
	free(line);
}
