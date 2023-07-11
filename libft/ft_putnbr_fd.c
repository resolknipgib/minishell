/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:52:46 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 05:01:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_print_digits(int *n, unsigned long *size, int fd, int *counter)
{
	char	c;

	c = (*n / *size) + 48;
	*n %= *size;
	write(fd, &c, 1);
	*size /= 10;
	(*counter)++;
}

static int	ft_print_zero(int n, int fd)
{
	char	c;

	c = 0;
	c = n + 48;
	write(fd, &c, 1);
	return (1);
}

static void	ft_print_minus(int *n, int fd, int *counter)
{
	char	c;

	c = '-';
	write(fd, &c, 1);
	*n = -*n;
	(*counter)++;
}

static int	ft_print_maxmin(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	ft_putstr_fd("2147483647", fd);
	return (10);
}

int	ft_putnbr_fd(int n, int fd)
{
	unsigned long	size;
	int				temp;
	int				counter;

	counter = 0;
	if (n == -2147483648 || n == 2147483647)
		return (ft_print_maxmin(n, fd));
	size = 1;
	if (n == 0)
		return (ft_print_zero(n, fd));
	if (n < 0)
		ft_print_minus(&n, fd, &counter);
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		size *= 10;
	}
	size /= 10;
	while (size > 0)
		ft_print_digits(&n, &size, fd, &counter);
	return (counter);
}
