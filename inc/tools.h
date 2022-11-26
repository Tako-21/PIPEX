/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:24:33 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/26 17:58:23 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

/* The open() system call requires these preprocessor directives  */
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>

/* Definition of boolean type  */
typedef enum e_bool
{
			FALSE,
			TRUE
}			t_bool;

/* Definition of ERROR_SIGNAL  */
typedef enum e_sig_err {
	ERR_OPEN,
	ERR_ARG,
	ERR_EXIST,
	ERR_EXE,
	ERR_FORK,
	ERR_PIPE,
	ERR_MEM,
	ERR_ENV,
	ERR_PATH,
	ERR__LENGHT
}	t_sig_err;

/* It required by exit_error in <main.c> to handle differents
   types of errors  */
typedef struct s_error
{
	int		sig_err;
	char	*sig_msg;
}			t_error;

typedef struct s_storage_cmd
{
	char					**path;
	char					**bin_args;
	char					*bin_path;
	char					*bin;
	int						pos;
	struct s_storage_cmd	*next;
}					t_storage_cmd;

typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**env;
}			t_args;

typedef struct s_data
{
	int				pfd[2];
	int				fd_in;
	int				fd[2];
	unsigned int	nb_cmd;
	t_args			args;
	t_storage_cmd	*storage;
}			t_data;

#endif
