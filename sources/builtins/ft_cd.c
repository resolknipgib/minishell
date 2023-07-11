/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:09 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:39:10 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	ft_change_path(t_tools *tools)
{
	char	*temp;

	temp = ft_strdup(tools->pwd);
	free(tools->old_pwd);
	tools->old_pwd = temp;
	free(tools->pwd);
	tools->pwd = getcwd(NULL, sizeof(NULL));
}

static char	*ft_find_path_ret(char *str, t_tools *tools)
{
	int	i;

	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], str, ft_strlen(str)))
			return (ft_substr(tools->envp[i], ft_strlen(str),
					ft_strlen(tools->envp[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

static int	ft_find_specific_path(t_tools *tools, char *str)
{
	char	*temp;
	int		result;

	temp = ft_find_path_ret(str, tools);
	result = chdir(temp);
	free(temp);
	if (result != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (result);
}

static void	ft_add_path_to_env(t_tools *tools)
{
	int		i;
	char	*temp;

	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], "PWD=", 4))
		{
			temp = ft_strjoin("PWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = temp;
		}
		else if (!ft_strncmp(tools->envp[i], "OLDPWD=", 7) && tools->old_pwd)
		{
			temp = ft_strjoin("OLDPWD=", tools->old_pwd);
			free(tools->envp[i]);
			tools->envp[i] = temp;
		}
		i++;
	}
}

int	ft_cd(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int	result;

	if (!simple_cmd->str[1])
		result = ft_find_specific_path(tools, "HOME=");
	else if (ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
		result = ft_find_specific_path(tools, "OLDPWD=");
	else
	{
		result = chdir(simple_cmd->str[1]);
		if (result != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(simple_cmd->str[1], STDERR_FILENO);
			perror(" ");
		}
	}
	if (result != 0)
		return (EXIT_FAILURE);
	ft_change_path(tools);
	ft_add_path_to_env(tools);
	return (EXIT_SUCCESS);
}
