/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 02:47:23 by karai             #+#    #+#             */
/*   Updated: 2024/12/24 02:47:59 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_access(char *full_path)
{
	if (access(full_path, F_OK) == 0)
	{
		if (access(full_path, X_OK) == 0)
			return (2);
		else
			return (1);
	}
	return (0);
}

bool	is_full_relative_path(char *str)
{
	if (str == NULL)
		return (false);
	if (str[0] == '.' || str[0] == '/')
		return (true);
	return (false);
}

void	initialize_data(t_data *data)
{
	data->cmd[0] = NULL;
	data->cmd[1] = NULL;
	data->path[0] = NULL;
	data->path[1] = NULL;
}