/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 08:44:46 by karai             #+#    #+#             */
/*   Updated: 2024/11/03 09:54:16 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_format(va_list args, char format, int *cnt)
{
	if (format == 'c')
		ft_putchar_fd_cnt(va_arg(args, int), 1, cnt);
	if (format == 's')
		ft_putstr_fd_cnt(va_arg(args, char *), 1, cnt);
	if (format == '%')
		ft_putchar_fd_cnt('%', 1, cnt);
	if (format == 'd' || format == 'i')
		ft_putnbr_fd_cnt(va_arg(args, int), 1, cnt);
	if (format == 'u')
		ft_putnbr_uint(va_arg(args, unsigned int), cnt);
	if (format == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef", cnt);
	if (format == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF", cnt);
	if (format == 'p')
		ft_putptr((unsigned long long)va_arg(args, void *), cnt);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		cnt;

	cnt = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (ft_is_format(str[1]))
				ft_printf_format(args, str[1], &cnt);
			else
			{
				va_end(args);
				return (-1);
			}
			str = str + 2;
		}
		else
			ft_putchar_fd_cnt(*str++, 1, &cnt);
	}
	va_end(args);
	return (cnt);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int				num;
// 	unsigned int	u_num;
// 	int				hex_x;
// 	int				hex_X;
// 	char			*str;

// 	int ret_val1, ret_val2;
// 	str = "asdf";
// 	num = 8998;
// 	u_num = 28917894;
// 	hex_x = -1;
// 	hex_X = -1;
// 	// ret_val1 = ft_printf("start %s %d %s %c %%
//%u %x %X %p finish\n", "aa",num,
// 	// 		"adfad", 'g', u_num, hex_x, hex_X, str);
// 	// printf("%d\n", ret_val1);
// 	// ret_val2 = printf("start %s %d %s %c %% %u %x %X %p finish\n", "aa", num,
// 	// 		"adfad", 'g', u_num, hex_x, hex_X, str);
// 	// printf("%d\n", ret_val2);

// 	ret_val1 = ft_printf(" %p %p ", 0, 0);
// 	printf("%d\n", ret_val1);
// 	// ret_val2 = printf(" %p %p ", 0, 0);
// 	// printf("%d\n", ret_val2);
// }
