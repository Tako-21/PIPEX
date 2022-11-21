/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:39:48 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/20 17:50:38 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_h

#include "tools.h"

void	exe_lastbin(t_data *data);
void	exe_firstbin(t_data *data);
void	exe_bin(t_data *data, int read, int write);

#endif
