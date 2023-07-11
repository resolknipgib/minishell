/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_executor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:40 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:39:42 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_prepare_executor(t_tools *tools)
{
	signal(SIGQUIT, ft_sigquit_handler);
	g_global.in_cmd = 1;
	if (tools->pipes == 0)
		ft_single_cmd(tools->simple_cmds, tools);
	else
	{
		tools->pid = ft_calloc(sizeof(int), tools->pipes + 2);
		if (!tools->pid)
			return (ft_error(1, tools));
		ft_start_executor(tools);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}
