/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:01 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:44:17 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "minishell.h"

char			**ft_arrdup(char **arr);

void			ft_free_arr(char **split_arr);

char			**ft_resplit_str(char **double_arr);

int				ft_check_valid_identifier(char c);

size_t			ft_equal_sign(char *str);

char			*ft_delete_quotes_value(char *str);

int				ft_count_quotes(char *line);

char			*delete_quotes(char *str, char c);

int				ft_init_tools(t_tools *tools);

int				ft_reset_tools(t_tools *tools);

void			ft_sigquit_handler(int sig);

void			ft_init_signals(void);

t_simple_cmds	*ft_simple_cmdsnew(char **str,
					int num_redirections, t_lexer *redirections);

void			ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new);

void			ft_simple_cmdsclear(t_simple_cmds **lst);

t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);

#endif
