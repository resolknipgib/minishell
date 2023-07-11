/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:38:25 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:38:29 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_echo(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_cd(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_pwd(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_export(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_unset(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_env(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_exit(t_tools *tools, t_simple_cmds *simple_cmd);

#endif
