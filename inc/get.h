/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:41:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 17:42:16 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

# include "tools.h"

char	*get_bin(char	*sh_command);
char	**get_path(char	*env[]);

#endif
