/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:24 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:39:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	**ft_whileloop_del_var(char **arr, char **rtn, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i] != NULL)
	{
		if (!(ft_strncmp(arr[i], str, ft_equal_sign(arr[i]) - 1) == 0
				&& str[ft_equal_sign(arr[i])] == '\0'
				&& arr[i][ft_strlen(str)] == '='))
		{
			rtn[j] = ft_strdup(arr[i]);
			if (rtn[j] == NULL)
			{
				ft_free_arr(rtn);
				return (rtn);
			}
			j++;
		}
		i++;
	}
	return (rtn);
}

static char	**ft_del_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	rtn = ft_whileloop_del_var(arr, rtn, str);
	return (rtn);
}

static int	ft_unset_error(t_simple_cmds *simple_cmd)
{
	int		i;

	i = 0;
	if (!simple_cmd->str[1])
	{
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (simple_cmd->str[1][i])
	{
		if (simple_cmd->str[1][i++] == '/')
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(simple_cmd->str[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	if (ft_equal_sign(simple_cmd->str[1]) != 0)
	{
		ft_putendl_fd("minishell: unset: not a valid identifier",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_unset(t_tools *tools, t_simple_cmds *simple_cmd)
{
	char	**temp;

	if (ft_unset_error(simple_cmd) == 1)
		return (EXIT_FAILURE);
	else
	{
		temp = ft_del_var(tools->envp, simple_cmd->str[1]);
		ft_free_arr(tools->envp);
		tools->envp = temp;
	}
	return (EXIT_SUCCESS);
}
