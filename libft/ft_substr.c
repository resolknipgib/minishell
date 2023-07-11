/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:41:13 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 05:01:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_get_str(char const *s, unsigned int start,
						size_t len, char *substr)
{
	while (s[start] && len > 0)
	{
		*substr = s[start];
		start++;
		substr++;
		len--;
	}
	*substr = '\0';
}

static size_t	ft_find_substrlen(char const *s, unsigned int start, size_t len)
{
	size_t	substrlen;

	substrlen = 0;
	while (s[start] && len > 0)
	{
		start++;
		substrlen++;
		len--;
	}
	return (substrlen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*result;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = (char *)malloc(1);
		*result = '\0';
		return (result);
	}
	if (s[start] && len >= 0)
	{
		substr = (char *)malloc(ft_find_substrlen(s, start, len) + 1);
		if (substr == NULL)
			return (NULL);
		result = substr;
		ft_get_str(s, start, len, substr);
		return (result);
	}
	return (NULL);
}
