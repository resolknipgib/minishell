/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:19 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:39:20 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_variable_exist(t_tools *tools, char *str)
{
	int	i;

	i = 0;
	if (str[ft_equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[ft_equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (tools->envp[i])
	{
		if (ft_strncmp(tools->envp[i],
				str, ft_equal_sign(tools->envp[i])) == 0)
		{
			free(tools->envp[i]);
			tools->envp[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_parameter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (ft_export_error(str));
	if (ft_equal_sign(str) == 0)
		return (EXIT_FAILURE);
	if (str[0] == '=')
		return (ft_export_error(str));
	while (str[i] != '=')
	{
		if (ft_check_valid_identifier(str[i]))
			return (ft_export_error(str));
		i++;
	}
	return (EXIT_SUCCESS);
}

static char	**ft_whileloop_ft_add_var(char **arr, char **rtn, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i + 1] == NULL)
		{
			rtn[i] = ft_strdup(str);
			rtn[i + 1] = ft_strdup(arr[i]);
		}
		else
			rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			ft_free_arr(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}

static char	**ft_add_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	if (str[ft_equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[ft_equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 2);
	if (!rtn)
		return (NULL);
	i = 0;
	ft_whileloop_ft_add_var(arr, rtn, str);
	return (rtn);
}

int	ft_export(t_tools *tools, t_simple_cmds *simple_cmd)
{
	char	**temp;
	int		i;

	i = 1;
	if (!simple_cmd->str[1] || simple_cmd->str[1][0] == '\0')
		ft_env(tools, simple_cmd);
	else
	{
		while (simple_cmd->str[i])
		{
			if (ft_check_parameter(simple_cmd->str[i]) == 0
				&& ft_variable_exist(tools, simple_cmd->str[i]) == 0)
			{
				if (simple_cmd->str[i])
				{
					temp = ft_add_var(tools->envp, simple_cmd->str[i]);
					ft_free_arr(tools->envp);
					tools->envp = temp;
				}
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
