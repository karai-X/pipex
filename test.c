/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:35:24 by karai             #+#    #+#             */
/*   Updated: 2024/12/23 23:04:02 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"
#include <stdio.h>

int	main(void)
{
	extern char	**environ;
	char		*cmd[3];
	int			a;

	cmd[0] = "./test_ok.sh";
	cmd[1] = NULL;
	cmd[2] = NULL;
	a = execve(cmd[0], cmd, environ);
	if (a == -1)
	{
		perror("error");
	}
	return (0);
}
