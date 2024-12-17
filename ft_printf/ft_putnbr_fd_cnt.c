/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_cnt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:24:59 by karai             #+#    #+#             */
/*   Updated: 2024/12/17 21:43:56 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_minus(long long *nb, int fd, int *cnt)
{
	if (*nb < 0)
	{
		*nb = -*nb;
		ft_putchar_fd_cnt('-', fd, cnt);
	}
}

void	ft_putnbr_fd_cnt(int n, int fd, int *cnt)
{
	int			div;
	long long	tmp;
	char		num_char;
	long long	nb_long;

	nb_long = (long long)n;
	ft_putnbr_minus(&nb_long, fd, cnt);
	div = 1;
	tmp = nb_long;
	while (tmp / 10 != 0)
	{
		div *= 10;
		tmp = tmp / 10;
	}
	while (div != 0)
	{
		num_char = '0' + (nb_long / div % 10);
		ft_putchar_fd_cnt(num_char, fd, cnt);
		div = div / 10;
	}
}
