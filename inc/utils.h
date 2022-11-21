/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:15:13 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/21 18:46:01 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "tools.h"
# define BUFFER_SIZE 1

void		ft_putstr_fd(char *s, int fd);
char 		*ft_strnchr(const char *s1, const char *s2, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strjoin_path(char *line, char *buffer);
char		**ft_split(char const *s, char c);
void		freemem(t_data *data);
void		mcollect(t_collector **lst, void	*addr_malloc);
int			lstsize(t_collector *st);
void		lstfree(t_collector **lst);
char		*ft_strdup(const char *src);
t_bool		ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char *line, char *buffer);
char		*get_next_line(int fd);
#endif
