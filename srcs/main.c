/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:28:42 by karai             #+#    #+#             */
/*   Updated: 2024/12/24 03:18:05 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(t_data *data, char *argv[], char *envp[])
{
	data->in_out_fd[0] = open(argv[1], O_RDONLY);
	if (data->in_out_fd[0] == -1)
		perror_exit(argv[1], NULL, NULL, 1);
	if (dup2(data->in_out_fd[0], 0) == -1)
		perror_exit("dup2 failed", NULL, NULL, 1);
	if (close(data->in_out_fd[0]) == -1)
		perror_exit("close failed", NULL, NULL, 1);
	if (close(data->pipefd[0]) == -1)
		perror_exit("close_failed", NULL, NULL, 1);
	if (dup2(data->pipefd[1], 1) == -1)
		perror_exit("dup2_failed", NULL, NULL, 1);
	if (close(data->pipefd[1]) == -1)
		perror_exit("close_failed", NULL, NULL, 1);
	data->cmd[0] = ft_split(argv[2], ' ');
	if (data->cmd[0] == NULL)
		perror_exit("malloc failed", NULL, NULL, 1);
	data->path[0] = get_path_main(envp, data->cmd[0]);
	if (execve(data->path[0], data->cmd[0], envp) == -1)
		perror_exit("execve failed", NULL, NULL, 1);
}

void	second_cmd(t_data *data, char *argv[], char *envp[])
{
	if (close(data->pipefd[1]) == -1)
		perror_exit("close failed", NULL, NULL, 1);
	if (dup2(data->pipefd[0], 0) == -1)
		perror_exit("dup2 failed", NULL, NULL, 1);
	if (close(data->pipefd[0]) == -1)
		perror_exit("close failed", NULL, NULL, 1);
	data->in_out_fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (data->in_out_fd[1] == -1)
		perror_exit(argv[4], NULL, NULL, 1);
	if (dup2(data->in_out_fd[1], 1) == -1)
		perror_exit("dup2 failed", NULL, NULL, 1);
	if (close(data->in_out_fd[1]) == -1)
		perror_exit("close failed", NULL, NULL, 1);
	data->cmd[1] = ft_split(argv[3], ' ');
	if (data->cmd[1] == NULL)
		perror_exit("malloc failed", NULL, NULL, 1);
	data->path[1] = get_path_main(envp, data->cmd[1]);
	if (execve(data->path[1], data->cmd[1], envp) == -1)
		perror_exit("execve failed", NULL, NULL, 1);
}

int	parent_process(t_data *data, pid_t pid[2])
{
	int	status;

	if (close(data->pipefd[0]) == -1)
		perror_exit("close failed", NULL, NULL, 1);
	if (close(data->pipefd[1]) == -1)
		perror_exit("close failed", NULL, NULL, 1);
	if (waitpid(pid[0], &status, 0) == -1)
		perror_exit("wait failed", NULL, NULL, 1);
	if (waitpid(pid[1], &status, 0) == -1)
		perror_exit("wait failed", NULL, NULL, 1);
	if (WIFSIGNALED(status))
		return (WIFSIGNALED(status));
	return (WEXITSTATUS(status));
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	pid_t	pid[2];

	if (argc != 5)
		exit(1);
	initialize_data(&data);
	if (pipe(data.pipefd) == -1)
		perror_exit("pipe failed", NULL, NULL, 1);
	pid[0] = fork();
	if (pid[0] == 0)
		first_cmd(&data, argv, envp);
	pid[1] = fork();
	if (pid[1] == 0)
		second_cmd(&data, argv, envp);
	return (parent_process(&data, pid));
}
