/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resplit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:30 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:40:32 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static char	*ft_join_split_str(char **split_str, char *new_str)
{
	char	*temp;
	char	*add_space;
	int		i;

	temp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		new_str = temp;
		add_space = ft_strjoin(new_str, " ");
		free(new_str);
		temp = ft_strjoin(add_space, split_str[i]);
		free(add_space);
		i++;
	}
	new_str = temp;
	return (new_str);
}

char	**ft_resplit_str(char **double_arr)
{
	char	**result;
	char	*joined_str;

	joined_str = ft_join_split_str(double_arr, NULL);
	ft_free_arr(double_arr);
	result = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = ft_join_split_str(result, NULL);
	ft_free_arr(result);
	result = ft_split(joined_str, ' ');
	free(joined_str);
	return (result);
}
