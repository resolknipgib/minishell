/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:14 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:40:15 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser_tools	ft_init_parser_tools(t_lexer *lexer_list, t_tools *tools)
{
	t_parser_tools	parser_tools;

	parser_tools.lexer_list = lexer_list;
	parser_tools.redirections = NULL;
	parser_tools.num_redirections = 0;
	parser_tools.tools = tools;
	return (parser_tools);
}

void	ft_count_pipes(t_lexer *lexer_list, t_tools *tools)
{
	t_lexer	*temp;

	temp = lexer_list;
	tools->pipes = 0;
	while (temp)
	{
		if (temp->token == PIPE)
			tools->pipes++;
		temp = temp->next;
	}
}

int	ft_count_args(t_lexer *lexer_list)
{
	t_lexer	*temp;
	int		i;

	i = 0;
	temp = lexer_list;
	while (temp && temp->token != PIPE)
	{
		if (temp->i >= 0)
			i++;
		temp = temp->next;
	}
	return (i);
}
