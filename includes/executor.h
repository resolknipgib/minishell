/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:38:37 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:38:38 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

int				ft_check_redirections(t_simple_cmds *cmd);

int				ft_start_executor(t_tools *tools);

t_simple_cmds	*ft_call_expander(t_tools *tools, t_simple_cmds *cmd);

int				ft_pipe_wait(int *pid, int amount);

void			ft_dup_cmd(t_simple_cmds *cmd, t_tools *tools,
					int end[2], int fd_in);

void			ft_single_cmd(t_simple_cmds *cmd, t_tools *tools);

int				ft_send_heredoc(t_tools *tools, t_simple_cmds *cmd);

int				ft_prepare_executor(t_tools *tools);

#endif
