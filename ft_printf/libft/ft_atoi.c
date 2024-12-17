/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:17:16 by karai             #+#    #+#             */
/*   Updated: 2024/10/30 19:14:19 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	ans;
	int	pm;

	ans = 0;
	pm = 1;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		nptr += 1;
	if (*nptr == '-')
		pm = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr += 1;
	while (*nptr <= '9' && *nptr >= '0' )
	{
		ans = ans * 10 + (*nptr - '0');
		nptr += 1;
	}
	return (ans * pm);
}

// #include <limits.h>
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", INT_MIN);
// 	char *a = "-2147483649";
// 	printf("%d\n", ft_atoi(a));
// 	printf("%d\n", atoi(a));
// 	char *n = "\t\v\f\r\n \f-06050";
// 	printf("%d\n", ft_atoi(n));
// 	printf("%d\n", atoi(n));
// }
