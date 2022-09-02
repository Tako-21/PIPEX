/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:24:33 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/02 14:19:49 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

/* The open() system call requires these preprocessor directives  */
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

/*Definition of ERROR_SIGNAL */
typedef enum e_sig_err {SIGERR}	t_sig_err;

typedef struct s_error
{
	int		sig_err;
	char	*sig_msg;
}			t_error;

#endif