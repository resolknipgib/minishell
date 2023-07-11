/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:30:31 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 05:01:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			move;
	size_t			i;
	unsigned char	*newdst;
	unsigned char	*newsrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	move = 1;
	newdst = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	if (dst > src)
	{
		move = -1;
		newdst = (unsigned char *)(dst + len - 1);
		newsrc = (unsigned char *)(src + len - 1);
	}
	i = 0;
	while (i < len)
	{
		*newdst = *newsrc;
		newdst += move;
		newsrc += move;
		i++;
	}
	return (dst);
}
