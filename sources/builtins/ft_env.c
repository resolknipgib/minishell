/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:14 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:39:15 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int		i;

	(void) simple_cmd;
	i = 0;
	while (tools->envp[i])
	{
		ft_putendl_fd(tools->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
