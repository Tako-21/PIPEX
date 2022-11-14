/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:15:13 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/14 20:12:50 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void		ft_putstr_fd(char *s, int fd);
static void	ft_putchar_fd(char c, int fd);
char 		*ft_strnchr(const char *s1, const char *s2, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *line, char *buffer);
char		**ft_split(char const *s, char c);
void		freemem(int argc, t_data *data);
void		free_array(char **arr);
void		ft_lstpush(t_collector **lst, void	*addr_malloc);
int			ft_lstsize(t_collector *st);

#endif