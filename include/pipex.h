/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:24:32 by karai             #+#    #+#             */
/*   Updated: 2024/12/24 02:55:38 by karai            ###   ########.fr       */
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
# define NO_PERMISSION 126

typedef struct s_data
{
	char	**cmd[2];
	int		pipefd[2];
	int		in_out_fd[2];
	char	*path[2];
	bool	tf_file[2];
}			t_data;

void		first_cmd(t_data *data, char *argv[], char *envp[]);

int			is_access(char *full_path);
bool		is_full_relative_path(char *str);
void		initialize_data(t_data *data);

void		perror_exit(char *str, char **str_array1, char **str_array2,
				int exit_status);
void		free2dim(char **str_array);
void		free_exit(char **str_array1, char **str_array2, int exit_status);

char		*get_path_cmd_part(char **dir_array, char **cmd, char *tmp_str);
char		*get_path_cmd(char *path_line, char **cmd);
char		*get_path_cmd_not_find_path(char **cmd);
char		*get_path_main(char *envp[], char **cmd);

#endif
