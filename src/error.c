/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:45:35 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/12 12:45:00 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"
#include <unistd.h>
#include "tools.h"
#include <stdlib.h>
#include "utils.h"
#include <stdio.h>

void	exit_error(int sig_err)
{
	const char	*map_error[ERR__LENGHT] = {
		"Error while opening file\n",
		"Too few arguments\n",
		"Too many arguments\n",
		"No such file or directory\n",
		"Command not found\n",
		"An error occurred while executing fork\n"
		"An error occurred while executing pipe\n"
	};
	ft_putstr_fd((char *)map_error[sig_err], STDERR_FILENO);
	exit(EXIT_FAILURE);
}
