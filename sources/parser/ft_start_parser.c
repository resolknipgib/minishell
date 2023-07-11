/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:10 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:40:11 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_simple_cmds	*ft_initialize_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*temp;

	i = 0;
	ft_rm_redirections(parser_tools);
	arg_size = ft_count_args(parser_tools->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		ft_parser_error(1, parser_tools->tools, parser_tools->lexer_list);
	temp = parser_tools->lexer_list;
	while (arg_size > 0)
	{
		if (temp->str)
		{
			str[i++] = ft_strdup(temp->str);
			ft_lexerdelone(&parser_tools->lexer_list, temp->i);
			temp = parser_tools->lexer_list;
		}
		arg_size--;
	}
	return (ft_simple_cmdsnew(str,
			parser_tools->num_redirections, parser_tools->redirections));
}

static int	ft_handle_pipe_errors(t_tools *tools, t_tokens token)
{
	if (token == PIPE)
	{
		ft_parser_token_error(tools, tools->lexer_list,
			tools->lexer_list->token);
		return (EXIT_FAILURE);
	}
	if (!tools->lexer_list)
	{
		ft_parser_error(0, tools, tools->lexer_list);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_start_parser(t_tools *tools)
{
	t_simple_cmds	*node;
	t_parser_tools	parser_tools;

	tools->simple_cmds = NULL;
	ft_count_pipes(tools->lexer_list, tools);
	if (tools->lexer_list->token == PIPE)
		return (ft_parser_token_error(tools, tools->lexer_list,
				tools->lexer_list->token));
	while (tools->lexer_list)
	{
		if (tools->lexer_list && tools->lexer_list->token == PIPE)
			ft_lexerdelone(&tools->lexer_list, tools->lexer_list->i);
		if (ft_handle_pipe_errors(tools, tools->lexer_list->token))
			return (EXIT_FAILURE);
		parser_tools = ft_init_parser_tools(tools->lexer_list, tools);
		node = ft_initialize_cmd(&parser_tools);
		if (!node)
			ft_parser_error(0, tools, parser_tools.lexer_list);
		if (!tools->simple_cmds)
			tools->simple_cmds = node;
		else
			ft_simple_cmdsadd_back(&tools->simple_cmds, node);
		tools->lexer_list = parser_tools.lexer_list;
	}
	return (EXIT_SUCCESS);
}
