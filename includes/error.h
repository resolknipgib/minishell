/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:38:32 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:38:36 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

void	ft_parser_error(int error, t_tools *tools, t_lexer *lexer_list);

int		ft_parser_token_error(t_tools *tools, t_lexer *lexer_list,
			t_tokens token);

void	ft_lexer_error(int error, t_tools *tools);

int		ft_cmd_error(char *str);

int		ft_export_error(char *c);

int		ft_error(int error, t_tools *tools);

#endif
