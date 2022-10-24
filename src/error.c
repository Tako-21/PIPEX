/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:45:35 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/24 16:01:37 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"
#include <unistd.h>
#include "tools.h"
#include <stdlib.h>
#include "utils.h"

void	exit_error(int sig_err)
{
	const char	*map_error[ERR__LENGHT] = {
		"Error while opening file\n",
		"Too few arguments.\n",
		"Too many arguments.\n",
		"No such file or directory.\n",
		"Permission denied.\n"
	};
	ft_putstr_fd((char *)map_error[sig_err], STDERR_FILENO);
	exit(EXIT_FAILURE);
}
