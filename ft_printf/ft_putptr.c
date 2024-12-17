/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:41:15 by karai             #+#    #+#             */
/*   Updated: 2024/11/03 08:45:23 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr_recursive(unsigned long long nb, char *hex_char, int *cnt)
{
	if (nb < 16)
		return (ft_putchar_fd_cnt(hex_char[nb], 1, cnt));
	ft_putptr_recursive(nb / 16, hex_char, cnt);
	ft_putchar_fd_cnt(hex_char[nb % 16], 1, cnt);
}

void	ft_putptr(unsigned long long nb, int *cnt)
{
	if (nb == 0)
	{
		ft_putstr_fd_cnt("(nil)", 1, cnt);
		return ;
	}
	ft_putchar_fd_cnt('0', 1, cnt);
	ft_putchar_fd_cnt('x', 1, cnt);
	ft_putptr_recursive(nb, "0123456789abcdef", cnt);
}
