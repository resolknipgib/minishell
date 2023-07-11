/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:38:49 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:44:06 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

int				ft_handle_quotes(int i, char *str, char del);

t_lexer			*ft_lexernew(char *str, int token);

void			ft_lexeradd_back(t_lexer **lst, t_lexer *new);

void			ft_lexerdelone(t_lexer **lst, int i);

void			ft_lexerclear(t_lexer **lst);

int				ft_add_lexer_unit(char *str, t_tokens token,
					t_lexer **lexer_list);

int				ft_token_reader(t_tools *tools);

t_tokens		ft_check_token(int c);

int				ft_handle_token(char *str, int i, t_lexer **lexer_list);

#endif
