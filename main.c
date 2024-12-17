/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:28:42 by karai             #+#    #+#             */
/*   Updated: 2024/12/17 22:14:15 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	extern char	**environ;
	char		**cmd;
	int			pipefd[2];
	pid_t		pid;
	int			in_fd;
	int			out_fd;
	char		str[100];
	int			tmp;

	if (argc != 5)
		exit(1);
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		// child process
		// read from file
		in_fd = open("./in.txt", O_RDONLY);
		dup2(in_fd, 0);
		close(in_fd);
		// output to pipe
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		// execute command
		cmd = ft_split(argv[2], ' ');
		execve("/bin/cat", cmd, environ);
		// exit(0);
	}
	// parent process
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	// write to file
	out_fd = open("./out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	dup2(out_fd, 1);
	close(out_fd);
	// execute command
	cmd = ft_split(argv[3], ' ');
	execve("/bin/wc", cmd, environ);
	return (0);
}
