/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:16 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:40:18 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	**ft_arrdup(char **arr)
{
	char	**result;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	result = ft_calloc(sizeof(char *), i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		result[i] = ft_strdup(arr[i]);
		if (result[i] == NULL)
		{
			ft_free_arr(result);
			return (result);
		}
		i++;
	}
	return (result);
}
