/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:38:46 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:47:08 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

char	**ft_start_expander(t_tools *tools, char **str);

char	*ft_start_expander_str(t_tools *tools, char *str);

size_t	ft_dollar_sign(char *str);

char	*ft_char_to_str(char c);

size_t	ft_after_dol_lenght(char *str, int j);

int		ft_question_mark(char **temp);

#endif
