/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigchld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:27:12 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/24 13:36:59 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <bits/sigaction.h>
#include <string.h>
#include <stdio.h>

sig_atomic_t	child_exit_status;

void clean_up_child_process (int signal_number)
{
	printf("Hello from handler !\n");
	/* Nettoie le ou les processus fils. */
	int status;
	while(waitpid (-1, &status, WNOHANG));
	/* Stocke la statut de sortie du dernier dans une variable globale.  */
	child_exit_status = status;
}

int	main(void)
{
	int	pid;
	struct	sigaction sigchld_action;

	memset(&sigchld_action, 0, sizeof(sigchld_action));
	sigchld_action.sa_handler = &clean_up_child_process;
	sigaction(SIGCHLD, &sigchld_action, NULL);

	// pid = fork();
	if (pid == 0)
	{
		printf("Hi we are in the child process\n");
	}
	else if (pid > 0)
	{
		printf("Hi we are in the parent process\n");
	}
	char	*p;
	printf("%s\n", p);
	return (21);
}