/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:38:34 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/06 19:34:25 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_path.h"
#include "tools.h"
#include "utils.h"
#include <stdio.h>

char	**get_path(char	*env[])
{
	char	*path;

	path = ft_strnchr(*env, "PATH", ft_strlen("PATH="));
	while (*env && !path)
	{
		path = ft_strnchr(*env, "PATH=", ft_strlen("PATH="));
		env++;
	}
	return (ft_split(path, ':'));
}
