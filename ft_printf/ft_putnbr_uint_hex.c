/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:42:18 by karai             #+#    #+#             */
/*   Updated: 2024/11/03 08:42:56 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uint(unsigned int nb, int *cnt)
{
	int				div;
	unsigned int	tmp;
	char			num_char;

	div = 1;
	tmp = nb;
	while (tmp / 10 != 0)
	{
		div *= 10;
		tmp = tmp / 10;
	}
	while (div != 0)
	{
		num_char = '0' + (nb / div % 10);
		ft_putchar_fd_cnt(num_char, 1, cnt);
		div = div / 10;
	}
}

void	ft_putnbr_hex(unsigned int nb, char *hex_char, int *cnt)
{
	if (nb < 16)
		return (ft_putchar_fd_cnt(hex_char[nb], 1, cnt));
	ft_putnbr_hex(nb / 16, hex_char, cnt);
	ft_putchar_fd_cnt(hex_char[nb % 16], 1, cnt);
}
