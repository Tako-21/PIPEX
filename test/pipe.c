/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:11:59 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/12 12:29:31 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **env)
{
	char		*msg1 = "Hello World #1\n";
	char		*msg2 = "Hello World #2\n";
	char		buf[15];
	int			fd[2];
	int			pid;
	int			w_status;
	char *const	args[] = {
		"ls",
		"-l"
	};

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		// wait(NULL);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execve("/usr/bin/ls", args, env);
		// write(fd[file_desc], msg1, 15);
		// write(fd[file_desc], msg2, 15);
	}
	else
	{
		waitpid(-1, &w_status, 0);
		char *const	args_wc[] = {
			"wc",
			"-l"
		};
		if (WIFEXITED(w_status))
			printf("child process exited normally\n");
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		execve("/usr/bin/wc", args_wc, env);
		for (int i = 0; i < 2; i++){
			if (read(fd[0], buf, 15) == -1)
				exit(EXIT_FAILURE);
			printf("%s", buf);
		}
		close(fd[0]);

	}
}