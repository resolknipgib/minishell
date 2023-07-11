/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:38:55 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 18:29:12 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

int				ft_parse_envp(t_tools *tools);

int				ft_find_pwd(t_tools *tools);

int				ft_start_parser(t_tools *tools);

t_parser_tools	ft_init_parser_tools(t_lexer *lexer_list, t_tools *tools);

void			ft_count_pipes(t_lexer *lexer_list, t_tools *tools);

int				ft_count_args(t_lexer *lexer_list);

void			ft_rm_redirections(t_parser_tools *parser_tools);

#endif
