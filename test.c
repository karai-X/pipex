/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:35:24 by karai             #+#    #+#             */
/*   Updated: 2024/12/22 13:45:45 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(void)
{
	extern char	**environ;
	char		*cmd[3];

	cmd[0] = ft_strdup("sleep");
	cmd[1] = ft_strdup("3");
	cmd[2] = NULL;
	execve("/usr/bin/sleep", cmd, environ);
	return (0);
}
