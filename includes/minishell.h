/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:38:52 by fabet             #+#    #+#             */
/*   Updated: 2022/10/16 16:38:54 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <dirent.h>

# include "libft.h"
# include "structures.h"
# include "parser.h"
# include "utilities.h"
# include "error.h"
# include "lexer.h"
# include "builtins.h"
# include "executor.h"
# include "expander.h"

int				ft_minishell_loop(t_tools *tools);

#endif
