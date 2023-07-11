/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:53:56 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 05:01:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*ptr;
	size_t	n;

	n = ft_strlen(s1) + 1;
	s2 = (char *)malloc(n);
	if (s2 == NULL)
	{
		return (NULL);
	}
	ptr = s2;
	while (n != 0)
	{
		*s2 = *s1;
		s1++;
		s2++;
		n--;
	}
	return (ptr);
}
