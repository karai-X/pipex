/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 08:48:49 by karai             #+#    #+#             */
/*   Updated: 2024/11/03 08:46:27 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>

void	ft_putchar_fd_cnt(char c, int fd, int *cnt);
void	ft_putstr_fd_cnt(char *s, int fd, int *cnt);
bool	ft_is_format(char c);
void	ft_putnbr_fd_cnt(int n, int fd, int *cnt);
void	ft_putnbr_uint(unsigned int nb, int *cnt);
void	ft_putnbr_hex(unsigned int nb, char *hex_char, int *cnt);
void	ft_putptr(unsigned long long nb, int *cnt);
void	ft_printf_format(va_list args, char format, int *cnt);
int		ft_printf(const char *str, ...);

#endif
