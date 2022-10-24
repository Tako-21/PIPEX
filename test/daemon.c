/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:12:12 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/19 18:50:52 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	pid;

	// pid = fork();

	printf("Hey\n");
	daemon(1, 1);
	sleep(5);
	printf("Yo\n");
	// if (pid == -1)
	// 	perror("fork");
	// else if (pid == 0)
	// {
	// 	// We are in the parent process
	// }
	// else if (pid > 0)
	// {
	// 	// We are in the child process

	// }
}