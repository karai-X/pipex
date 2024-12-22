/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:24:32 by karai             #+#    #+#             */
/*   Updated: 2024/12/22 17:03:29 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define NON_COMMAND 127
#define NO_PERMISSION 126

typedef struct s_data
{
	char	**cmd[2];
	int		pipefd[2];
	int		in_out_fd[2];
	char	*path[2];
}			t_data;

void		perror_free(char *str, int exit_status);
void	free2dim(char **str_array);

#endif
