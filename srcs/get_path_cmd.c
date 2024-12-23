/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:42:08 by karai             #+#    #+#             */
/*   Updated: 2024/12/24 00:58:08 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_cmd(char *path_line, char **cmd)
{
	char	**dir_array;
	char	*full_path;
	char	*tmp_str;
	int		i;

	dir_array = ft_split(&path_line[5], ':');
	i = 0;
	while (dir_array[i])
	{
		tmp_str = ft_strjoin(dir_array[i], "/");
		full_path = get_path_cmd_part(dir_array, cmd, tmp_str);
		if (full_path != NULL)
			return (full_path);
		i += 1;
	}
	ft_printf("%s command not found\n", cmd[0]);
	free_exit(dir_array, cmd, NON_COMMAND);
	return (NULL);
}

char	*get_path_cmd_part(char **dir_array, char **cmd, char *tmp_str)
{
	char	*full_path;
	int		access_status;

	if (tmp_str == NULL)
		perror_exit("malloc failed", dir_array, cmd, 1);
	full_path = ft_strjoin(tmp_str, cmd[0]);
	free(tmp_str);
	if (full_path == NULL)
		perror_exit("malloc failed", dir_array, cmd, 1);
	access_status = is_access(full_path);
	if (access_status == 2)
	{
		free2dim(dir_array);
		return (full_path);
	}
	free(full_path);
	if (access_status == 1)
	{
		ft_printf("'%s': Permission denied\n", cmd[0]);
		free_exit(dir_array, cmd, NO_PERMISSION);
	}
	return (NULL);
}

char	*get_path_cmd_not_find_path(char **cmd)
{
	char	*full_path;
	int		access_status;

	access_status = is_access(cmd[0]);
	if (access_status == 2)
	{
		full_path = cmd[0];
		return (full_path);
	}
	if (access_status == 1)
	{
		ft_printf("'%s': Permission denied\n", cmd[0]);
		free2dim(cmd);
		exit(NO_PERMISSION);
	}
	perror(cmd[0]);
	free2dim(cmd);
	exit(NON_COMMAND);
	return (NULL);
}

char	*get_path_main(char *envp[], char **cmd)
{
	size_t	i;
	char	*path_line;

	if (cmd[0] == NULL)
	{
		ft_printf("'': command not found\n");
		free_exit(NULL, cmd, NON_COMMAND);
	}
	if (is_full_relative_path(cmd[0]) == false)
	{
		i = 0;
		while (envp[i])
		{
			if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			{
				path_line = envp[i];
				return (get_path_cmd(path_line, cmd));
			}
			i += 1;
		}
		ft_printf("%s command not found\n", cmd[0]);
		exit(NON_COMMAND);
	}
	else
		return (get_path_cmd_not_find_path(cmd));
}
