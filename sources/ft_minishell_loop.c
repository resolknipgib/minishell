/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:41 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:40:43 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int	ft_minishell_loop(t_tools *tools)
{
	char	*temp;

	tools->args = readline("ms$ ");
	temp = ft_strtrim(tools->args, " ");
	free(tools->args);
	tools->args = temp;
	if (!tools->args)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (tools->args[0] == '\0')
		return (ft_reset_tools(tools));
	add_history(tools->args);
	if (!ft_count_quotes(tools->args))
		return (ft_error(2, tools));
	if (!ft_token_reader(tools))
		return (ft_error(1, tools));
	ft_start_parser(tools);
	ft_prepare_executor(tools);
	ft_reset_tools(tools);
	return (1);
}
