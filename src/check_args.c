/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:39:33 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/24 20:10:41 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "check_error.h"

void	parse_args(int argc)
{
	if (argc > 5)
		exit_error(ERR_ARG_HIGH);
	else if (argc < 5)
		exit_error(ERR_ARG_LOW);
}
