/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:44:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/20 15:20:21 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	pid;
	int	arr[100000] = {1,2,3};

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid > 0)
	{
		// We are in the parent process.
		arr[1] = 21;
		wait(&pid);
		printf("pid : %d\n", pid);
	}
	if (pid == 0)
	{
		// We are in the child process.
		sleep(3);
		printf("fils : arr[1] = %d\n", arr[1]);
	}
}
