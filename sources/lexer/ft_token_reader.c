/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:02 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:40:03 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

static int	ft_skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (ft_is_whitespace(str[i + j]))
		j++;
	return (j);
}

static int	ft_read_words(int i, char *str, t_lexer **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(ft_check_token(str[i + j])))
	{
		j += ft_handle_quotes(i + j, str, 34);
		j += ft_handle_quotes(i + j, str, 39);
		if (ft_is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	if (!ft_add_lexer_unit(ft_substr(str, i, j), 0, lexer_list))
		return (-1);
	return (j);
}

int	ft_token_reader(t_tools *tools)
{
	int		i;
	int		j;

	i = 0;
	while (tools->args[i])
	{
		j = 0;
		i += ft_skip_spaces(tools->args, i);
		if (ft_check_token(tools->args[i]))
			j = ft_handle_token(tools->args, i, &tools->lexer_list);
		else
			j = ft_read_words(i, tools->args, &tools->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}
