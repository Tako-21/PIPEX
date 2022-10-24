/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigchld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:00:25 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/22 17:25:51 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void	spwan(void)
// {
// 	int	pid;

// }

int	main(void)
{
	int	pid;
	int	child_status;

	printf("Start of the program\n");
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		sleep(3);
		printf("Hi we are in the child process\n");
	}
	else if (pid > 0)
	{
		sleep(3);
		printf("Hi we are in the parent process\n");
	}
	wait(&child_status);
	printf("going to sleep\n");
	sleep(3);
	if (WIFEXITED(child_status))
		printf("Child terminated with status : %d\n", WIFEXITED(child_status));
	else
		exit(EXIT_FAILURE);
	printf("End of the program\tpid : %d\n", pid);
}