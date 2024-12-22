/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:28:42 by karai             #+#    #+#             */
/*   Updated: 2024/12/22 21:15:10 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"
#include <stdio.h>

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

char	*get_path_cmd(char *path_line, char **cmd)
{
	char	**dir_array;
	char	*full_path;
	char	*tmp_str;
	int		i;
	int		access_status;

	dir_array = ft_split(&path_line[5], ':');
	i = 0;
	while (dir_array[i])
	{
		tmp_str = ft_strjoin(dir_array[i], "/");
		if (tmp_str == NULL)
		{
			free2dim(dir_array);
			free2dim(cmd);
			perror_free("malloc failed", 1);
		}
		full_path = ft_strjoin(tmp_str, cmd[0]);
		free(tmp_str);
		if (full_path == NULL)
		{
			free2dim(dir_array);
			free2dim(cmd);
			perror_free("malloc failed", 1);
		}
		access_status = is_access(full_path);
		if (access_status == 2)
		{
			free2dim(dir_array);
			return (full_path);
		}
		free(full_path);
		if (access_status == 1)
		{
			free2dim(dir_array);
			free2dim(cmd);
			ft_printf("'%s': Permission denied\n", cmd[0]);
			exit(NO_PERMISSION);
		}
		i += 1;
	}
	ft_printf("%s command not found\n", cmd[0]);
	free2dim(dir_array);
	free2dim(cmd);
	// exit(1);
	exit(NON_COMMAND);
}

char	*get_path_main(char *envp[], char **cmd)
{
	size_t	i;
	char	*path_line;
	char	*full_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_line = envp[i];
			full_path = get_path_cmd(path_line, cmd);
			return (full_path);
		}
		i += 1;
	}
	return (NULL);
}

void	initialize_data(t_data *data)
{
	data->cmd[0] = NULL;
	data->cmd[1] = NULL;
	data->path[0] = NULL;
	data->path[1] = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	pid_t	pid;
	int		wait_status;

	// char	tmp[100];
	initialize_data(&data);
	if (argc != 5)
		exit(1);
	if (pipe(data.pipefd) == -1)
		perror_free("pipe failed", 1);
	pid = fork();
	if (pid == 0)
	{
		// child process
		// read from file
		data.in_out_fd[0] = open(argv[1], O_RDONLY);
		if (data.in_out_fd[0] == -1)
			perror_free(argv[1], 1);
		if (dup2(data.in_out_fd[0], 0) == -1)
			perror_free("dup2 failed", 1);
		if (close(data.in_out_fd[0]) == -1)
			perror_free("close failed", 1);
		// output to pipe
		if (close(data.pipefd[0]) == -1)
			perror_free("close_failed", 1);
		if (dup2(data.pipefd[1], 1) == -1)
			perror_free("dup2_failed", 1);
		if (close(data.pipefd[1]) == -1)
			perror_free("close_failed", 1);
		// execute command
		data.cmd[0] = ft_split(argv[2], ' ');
		data.path[0] = get_path_main(envp, data.cmd[0]);
		if (execve(data.path[0], data.cmd[0], envp) == -1)
		{
			perror_free("execve failed", 1);
		}
	}
	else
	{
		wait(&wait_status);
		if (wait_status == -1)
			perror_free("wait failed", 1);
		// if (wait_status != 256)
		// 	exit(0);
		// parent process
		close(data.pipefd[1]);
		if (dup2(data.pipefd[0], 0) == -1)
			perror_free("dup2 failed", 1);
		if (close(data.pipefd[0]) == -1)
			perror_free("close failed", 1);
		// wait(&wait_status);
		// if (wait_status == -1)
		// 	perror_free("wait failed", 1);
		// write to file
		data.in_out_fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (data.in_out_fd[1] == -1)
			perror_free(argv[4], 1);
		if (dup2(data.in_out_fd[1], 1) == -1)
			perror_free("dup2 failed", 1);
		if (close(data.in_out_fd[1]) == -1)
			perror_free("close failed", 1);
		// execute command
		data.cmd[1] = ft_split(argv[3], ' ');
		data.path[1] = get_path_main(envp, data.cmd[1]);
		// wait(&wait_status);
		// if (wait_status == -1)
		// 	perror_free("wait failed", 1);
		execve(data.path[1], data.cmd[1], envp);
	}
	return (0);
}
