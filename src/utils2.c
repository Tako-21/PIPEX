/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:27:29 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/26 18:17:05 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "tools.h"
#include "error.h"
#include "get.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen((char *)src) + 1);
	if (!p)
		return (NULL);
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

t_bool	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (FALSE);
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	if (s1[i] == s2[i])
		return (TRUE);
	return (FALSE);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*p;
	int		i;
	int		j;

	j = 0;
	i = 0;
	p = malloc(sizeof(char) * (ft_strlen((char *)line)
				+ ft_strlen((char *)buffer)) + 1);
	if (!p)
		return (NULL);
	if (line != NULL)
	{
		while (line[i])
		{
			p[i] = line[i];
			i++;
		}
	}
	while (buffer[j])
		p[i++] = buffer[j++];
	p[i] = '\0';
	if (line != NULL)
		free(line);
	return (p);
}

void	add_node(t_storage_cmd **storage, char *cmd, char *env[])
{
	t_storage_cmd	*new;
	static int		pos = 1;

	new = malloc(sizeof(*new));
	if (!new)
		exit_error(ERR_MEM);
	new->next = (*storage);
	new->bin = get_bin(cmd);
	new->path = get_path(env);
	new->bin_args = get_bin_args(cmd, new->bin);
	new->bin_path = get_bin_path(cmd, new->bin, new->path);
	new->pos = pos;
	*(storage) = new;
	pos++;
}
