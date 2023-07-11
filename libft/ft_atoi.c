/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:41:19 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 17:35:48 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_get_result(int counter,
	long long int result, long long int sign)
{
	if (counter >= 20)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	return (result * sign);
}

long long int	ft_atoi(const char *str)
{
	long long int	sign;
	long long int	result;
	int				counter;

	sign = 1;
	result = 0;
	counter = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57 && counter < 20)
	{
		result = (*str - '0') + result * 10;
		str++;
		counter++;
	}
	return (ft_get_result(counter, result, sign));
}
