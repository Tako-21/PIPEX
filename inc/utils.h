/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:15:13 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/19 13:12:29 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "tools.h"

void		ft_putstr_fd(char *s, int fd);
char 		*ft_strnchr(const char *s1, const char *s2, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *line, char *buffer);
char		**ft_split(char const *s, char c);
void		freemem(t_data *data);
void		mcollect(t_collector **lst, void	*addr_malloc);
int			lstsize(t_collector *st);
void		lstfree(t_collector **lst);
char		*ft_strdup(const char *src);
void		init(int argc, char **argv, char **env, t_data *data);

#endif
