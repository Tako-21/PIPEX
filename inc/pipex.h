/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:51:43 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/21 17:58:38 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "tools.h"

void	init(int argc, char **argv, char **env, t_data *data);
void	pipex(t_data *data);
void	here_doc(t_data *data);

#endif
