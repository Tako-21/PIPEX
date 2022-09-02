/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/02 14:21:10 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	exit_error(int sig_err)
{
	t_error	map_error[3];

	map_error[0].sig_msg = "Error while opening file\n";
	map_error[0].sig_err =
	return (1);
}

int	main(int argc, char **argv)
{
	t_error	map_err;
	if (argc > 5)
		return (-1);
	if ((open(argv[1], O_RDONLY == -1) || (open(argv[4], O_RDONLY) == -1)))
		return (exit_error(SIGERR));
	return (21);
}