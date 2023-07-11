/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:39:19 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 05:01:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_dst_len(char **dst, size_t dstsize)
{
	char	*dst_start;
	size_t	n;
	size_t	dst_len;

	dst_start = *dst;
	n = dstsize;
	while (n != 0 && **dst != '\0')
	{
		(*dst)++;
		n--;
	}
	dst_len = *dst - dst_start;
	return (dst_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*new_src;
	size_t	n;
	size_t	dst_len;

	new_src = (char *)src;
	dst_len = ft_find_dst_len(&dst, dstsize);
	n = dstsize - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(src));
	n--;
	while ((*src != '\0') && (n != 0))
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	while (*src != '\0')
		src++;
	*dst = '\0';
	return (dst_len + (src - new_src));
}
