/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_simple_cmds_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:39 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:43:47 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

t_simple_cmds	*ft_simple_cmdsnew(char **str,
	int num_redirections, t_lexer *redirections)
{
	t_simple_cmds	*new_element;

	new_element = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->builtin = builtin_arr(str[0]);
	new_element->hd_file_name = NULL;
	new_element->num_redirections = num_redirections;
	new_element->redirections = redirections;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new)
{
	t_simple_cmds	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void	ft_simple_cmdsclear(t_simple_cmds **lst)
{
	t_simple_cmds	*temp;
	t_lexer			*redirections_temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		redirections_temp = (*lst)->redirections;
		ft_lexerclear(&redirections_temp);
		if ((*lst)->str)
			ft_free_arr((*lst)->str);
		if ((*lst)->hd_file_name)
			free((*lst)->hd_file_name);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map->prev != NULL)
	{
		map = map->prev;
		i++;
	}
	return (map);
}
