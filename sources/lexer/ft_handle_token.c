/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:53 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:39:54 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "lexer.h"

t_tokens	ft_check_token(int c)
{
	static int	token_arr[3][2] = {
	{'|', PIPE},
	{'>', GREAT},
	{'<', LESS},
	};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (token_arr[i][0] == c)
			return (token_arr[i][1]);
		i++;
	}
	return (0);
}

int	ft_handle_token(char *str, int i, t_lexer **lexer_list)
{
	t_tokens	token;

	token = ft_check_token(str[i]);
	if (token == GREAT && ft_check_token(str[i + 1]) == GREAT)
	{
		if (!ft_add_lexer_unit(NULL, GREAT_GREAT, lexer_list))
			return (-1);
		return (2);
	}
	else if (token == LESS && ft_check_token(str[i + 1]) == LESS)
	{
		if (!ft_add_lexer_unit(NULL, LESS_LESS, lexer_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!ft_add_lexer_unit(NULL, token, lexer_list))
			return (-1);
		return (1);
	}
	return (0);
}
