/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:39:48 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:45:41 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

static int	ft_loop_if_dollar_sign(t_tools *tools, char *str,
									char **temp, int j)
{
	int		k;
	int		result;
	char	*temp2;
	char	*temp3;

	k = 0;
	result = 0;
	while (tools->envp[k])
	{
		if (ft_strncmp(str + j + 1, tools->envp[k],
				ft_equal_sign(tools->envp[k]) - 1) == 0
			&& ft_after_dol_lenght(str, j) - j == ft_equal_sign(tools->envp[k]))
		{
			temp2 = ft_strdup(tools->envp[k] + ft_equal_sign(tools->envp[k]));
			temp3 = ft_strjoin(*temp, temp2);
			free(*temp);
			*temp = temp3;
			free(temp2);
			result = ft_equal_sign(tools->envp[k]);
		}
		k++;
	}
	if (result == 0)
		result = ft_after_dol_lenght(str, j) - j;
	return (result);
}

static int	ft_handle_digit_after_dollar(int j, char *str)
{
	int	i;

	i = j;
	if (str[j] == '$')
	{
		if (ft_isdigit(str[j + 1]) == 1)
		{
			j += 2;
		}
	}
	return (j - i);
}

static char	*ft_detect_dollar_sign(t_tools *tools, char *str)
{
	int		j;
	char	*temp;
	char	*temp2;
	char	*temp3;

	j = 0;
	temp = ft_strdup("\0");
	while (str[j])
	{
		j += ft_handle_digit_after_dollar(j, str);
		if (str[j] == '$' && str[j + 1] == '?')
			j += ft_question_mark(&temp);
		else if (str[j] == '$' && (str[j + 1] != ' ' && (str[j + 1] != '"'
					|| str[j + 2] != '\0')) && str[j + 1] != '\0')
			j += ft_loop_if_dollar_sign(tools, str, &temp, j);
		else
		{
			temp2 = ft_char_to_str(str[j++]);
			temp3 = ft_strjoin(temp, temp2);
			free(temp);
			temp = temp3;
			free(temp2);
		}
	}
	return (temp);
}

char	**ft_start_expander(t_tools *tools, char **str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (str[i] != NULL)
	{
		if (str[i][ft_dollar_sign(str[i]) - 2] != '\''
			&& ft_dollar_sign(str[i]) != 0
			&& str[i][ft_dollar_sign(str[i])] != '\0')
		{
			temp = ft_detect_dollar_sign(tools, str[i]);
			free(str[i]);
			str[i] = temp;
		}
		if (ft_strncmp(str[0], "export", ft_strlen(str[0]) - 1) != 0)
		{
			str[i] = delete_quotes(str[i], '\"');
			str[i] = delete_quotes(str[i], '\'');
		}
		i++;
	}
	return (str);
}

char	*ft_start_expander_str(t_tools *tools, char *str)
{
	char	*temp;

	temp = NULL;
	if (str[ft_dollar_sign(str) - 2] != '\'' && ft_dollar_sign(str) != 0
		&& str[ft_dollar_sign(str)] != '\0')
	{
		temp = ft_detect_dollar_sign(tools, str);
		free(str);
		str = temp;
	}
	str = delete_quotes(str, '\"');
	str = delete_quotes(str, '\'');
	return (str);
}
