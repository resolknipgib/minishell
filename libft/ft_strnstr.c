/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:36:05 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 05:01:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*temp_haystack;
	char	*temp_needle;
	char	*result;

	temp_haystack = (char *)haystack;
	temp_needle = (char *)needle;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while ((*temp_haystack) && (len >= ft_strlen(needle)))
	{
		result = temp_haystack;
		while (*temp_haystack == *temp_needle && *temp_needle)
		{
			temp_haystack++;
			temp_needle++;
		}
		if (!(*temp_needle))
			return (result);
		temp_needle = (char *)needle;
		temp_haystack = result + 1;
		len--;
	}
	return (NULL);
}
