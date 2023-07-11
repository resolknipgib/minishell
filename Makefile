NAME			=	minishell

CC				=	cc

FLAGS			=	-Wall -Werror -Wextra

RM				=	rm -rf

READLINE_DIR	=	$(shell brew --prefix readline)

READLINE_LIB	=	-lreadline -lhistory -L $(READLINE_DIR)/lib

LIBFT_DIR		=	libft

LIBFT			=	$(LIBFT_DIR)/libft.a

LIBFT_SOURCES	=	libft/ft_atoi.c \
					libft/ft_bzero.c \
					libft/ft_calloc.c \
					libft/ft_isalnum.c \
					libft/ft_isalpha.c \
					libft/ft_isascii.c \
					libft/ft_isdigit.c \
					libft/ft_isprint.c \
					libft/ft_itoa.c \
					libft/ft_lstadd_back_bonus.c \
					libft/ft_lstadd_front_bonus.c \
					libft/ft_lstclear_bonus.c \
					libft/ft_lstdelone_bonus.c \
					libft/ft_lstiter_bonus.c \
					libft/ft_lstlast_bonus.c \
					libft/ft_lstmap_bonus.c \
					libft/ft_lstnew_bonus.c \
					libft/ft_lstsize_bonus.c \
					libft/ft_memchr.c \
					libft/ft_memcmp.c \
					libft/ft_memcpy.c \
					libft/ft_memmove.c \
					libft/ft_memset.c \
					libft/ft_putchar_fd.c \
					libft/ft_putendl_fd.c \
					libft/ft_putnbr_fd.c \
					libft/ft_putstr_fd.c \
					libft/ft_split.c \
					libft/ft_strchr.c \
					libft/ft_strcmp.c \
					libft/ft_strdup.c \
					libft/ft_striteri.c \
					libft/ft_strjoin.c \
					libft/ft_strlcat.c \
					libft/ft_strlcpy.c \
					libft/ft_strlen.c \
					libft/ft_strmapi.c \
					libft/ft_strncmp.c \
					libft/ft_strnstr.c \
					libft/ft_strrchr.c \
					libft/ft_strtrim.c \
					libft/ft_substr.c \
					libft/ft_tolower.c \
					libft/ft_toupper.c

LIBFT_HEADER	=	libft/libft.h

INCLUDES		=	-Iincludes -I$(LIBFT_DIR) -I$(READLINE_DIR)/include

HEADERS			=	includes/builtins.h \
					includes/error.h \
					includes/executor.h \
					includes/lexer.h \
					includes/minishell.h \
					includes/parser.h \
					includes/utilities.h \
					includes/expander.h \
					includes/structures.h

SOURCES			=	sources/main.c \
					sources/ft_minishell_loop.c \
					 \
					sources/lexer/ft_handle_quotes.c \
					sources/lexer/ft_handle_token.c \
					sources/lexer/ft_token_reader.c \
					sources/lexer/ft_lexer_clear_utilities.c \
					sources/lexer/ft_lexer_utilities.c \
					 \
					sources/parser/ft_rm_redirections.c \
					sources/parser/ft_start_parser.c \
					sources/parser/ft_parse_envp.c \
					sources/parser/parser_utilities.c \
					 \
					sources/builtins/builtins.c \
					sources/builtins/ft_cd.c \
					sources/builtins/ft_echo.c \
					sources/builtins/ft_env.c \
					sources/builtins/ft_exit.c \
					sources/builtins/ft_export.c \
					sources/builtins/ft_pwd.c \
					sources/builtins/ft_unset.c \
					 \
					sources/utilities/ft_signals.c \
					sources/utilities/t_simple_cmds_utilities.c \
					sources/utilities/ft_arrdup.c \
					sources/utilities/ft_free_arr.c \
					sources/utilities/ft_quotes.c \
					sources/utilities/ft_tools.c \
					sources/utilities/ft_check_valid_identifier.c \
					sources/utilities/ft_equal_sign.c \
					sources/utilities/ft_resplit_str.c \
					 \
					sources/error/error_handling.c \
					sources/error/ft_error.c \
					 \
					sources/executor/ft_check_redirections.c \
					sources/executor/ft_start_executor.c \
					sources/executor/ft_handle_cmd.c \
					sources/executor/ft_heredoc.c \
					sources/executor/ft_prepare_executor.c \
					 \
					sources/expander/ft_start_expander.c \
					sources/expander/expanders_utilities.c

$(NAME): $(SOURCES) $(HEADERS) $(LIBFT_SOURCES) $(LIBFT_HEADER)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SOURCES) $(READLINE_LIB) -o $(NAME)

all: $(NAME)

clean:
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
