/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:07 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:40:08 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_add_new_redirection(t_lexer *temp, t_parser_tools *parser_tools)
{
	t_lexer	*node;
	int		index_1;
	int		index_2;

	node = ft_lexernew(ft_strdup(temp->next->str), temp->token);
	if (!node)
		ft_parser_error(1, parser_tools->tools, parser_tools->lexer_list);
	ft_lexeradd_back(&parser_tools->redirections, node);
	index_1 = temp->i;
	index_2 = temp->next->i;
	ft_lexerdelone(&parser_tools->lexer_list, index_1);
	ft_lexerdelone(&parser_tools->lexer_list, index_2);
	parser_tools->num_redirections++;
	return (0);
}

void	ft_rm_redirections(t_parser_tools *parser_tools)
{
	t_lexer	*temp;

	temp = parser_tools->lexer_list;
	while (temp && temp->token == 0)
		temp = temp->next;
	if (!temp || temp->token == PIPE)
		return ;
	if (!temp->next)
		ft_parser_error(0, parser_tools->tools, parser_tools->lexer_list);
	if (temp->next->token)
		ft_parser_token_error(parser_tools->tools,
			parser_tools->lexer_list, temp->next->token);
	if ((temp->token >= GREAT
			&& temp->token <= LESS_LESS))
		ft_add_new_redirection(temp, parser_tools);
	ft_rm_redirections(parser_tools);
}
