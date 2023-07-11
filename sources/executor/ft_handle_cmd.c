/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:35 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:39:36 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	ft_find_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->str = ft_resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
		execve(cmd->str[0], cmd->str, tools->envp);
	while (tools->paths[i])
	{
		mycmd = ft_strjoin(tools->paths[i], cmd->str[0]);
		if (!access(mycmd, F_OK))
			execve(mycmd, cmd->str, tools->envp);
		free(mycmd);
		i++;
	}
	return (ft_cmd_error(cmd->str[0]));
}

static void	ft_handle_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections)
		if (ft_check_redirections(cmd))
			exit(1);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(tools, cmd);
		exit(exit_code);
	}
	else if (cmd->str[0][0] != '\0')
		exit_code = ft_find_cmd(cmd, tools);
	exit(exit_code);
}

void	ft_dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(4, tools);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(4, tools);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	ft_handle_cmd(cmd, tools);
}

void	ft_single_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	pid;
	int	status;

	tools->simple_cmds = ft_call_expander(tools, tools->simple_cmds);
	if (cmd->builtin == ft_cd || cmd->builtin == ft_exit
		|| cmd->builtin == ft_export || cmd->builtin == ft_unset)
	{
		g_global.error_num = cmd->builtin(tools, cmd);
		return ;
	}
	ft_send_heredoc(tools, cmd);
	pid = fork();
	if (pid < 0)
		ft_error(5, tools);
	if (pid == 0)
		ft_handle_cmd(cmd, tools);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}
