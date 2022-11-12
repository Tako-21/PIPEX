/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:39:48 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/12 12:44:25 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_h

void	std_binin(char *bin_path, char **bin_args, char **env, t_data *data);
void	std_binout(char *bin_path, char **bin_args, char **env, t_data *data);

#endif