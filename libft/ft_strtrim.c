/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:12:20 by fabet             #+#    #+#             */
/*   Updated: 2022/03/26 05:01:30 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_is_set_char(char ch, char const *set)
{
	char	*ptr;

	ptr = (char *)set;
	while (*ptr)
	{
		if (*ptr == ch)
			return (1);
		ptr++;
	}
	return (0);
}

static char	*ft_empty_str(void)
{
	char	*new_str;

	new_str = (char *)malloc(1);
	*new_str = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*left;
	char	*right;
	char	*new_str;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	left = (char *)s1;
	right = (char *)s1;
	while (ft_is_set_char(*left, set))
		left++;
	while (*right)
		right++;
	if (right <= left)
		return (ft_empty_str());
	right--;
	while (ft_is_set_char(*right, set))
		right--;
	if (right <= s1)
		return (ft_empty_str());
	new_str = (char *)malloc(right - left + 2);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, left, right - left + 1);
	new_str[right - left + 1] = '\0';
	return (new_str);
}
