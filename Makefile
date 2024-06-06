# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 10:15:08 by wcorrea-          #+#    #+#              #
#    Updated: 2024/06/06 17:15:26 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/main.c \
	    src/signals.c \
	  	src/envp/envp1_convert.c \
	  	src/envp/envp2_create.c \
	  	src/envp/envp3_export_get_print.c \
	  	src/envp/envp4_mod.c \
		src/envp/envp5_rm.c \
		src/envp/envp6_clear.c \
	  	src/process_line/process_line.c \
	  	src/parser/parser.c \
	  	src/parser/parse_cmds.c \
	  	src/parser/node_constructors.c \
	  	src/expand/expand_arg.c \
	  	src/expand/expand_utils.c \
	  	src/expand/trim.c \
	  	src/error_frees/error_free.c \
	  	src/error_frees/free_cmd.c \
	  	src/run_cmd/checks.c \
	  	src/run_cmd/run_cmd.c \
	  	src/run_cmd/run_pipe.c \
	  	src/run_cmd/run_exec.c \
	  	src/run_cmd/run_redir.c \
	  	src/run_cmd/run_here.c \
	  	src/built_ins/run_builtin.c \
	  	src/built_ins/cd.c \
	  	src/built_ins/chdir.c \
	  	src/built_ins/echo.c \
	  	src/built_ins/env.c \
	  	src/built_ins/exit.c \
	  	src/built_ins/export.c \
	  	src/built_ins/pwd.c \
	  	src/built_ins/unset.c
	 
OBJS = ${SRC:.c=.o}

CC = clang
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -arch x86_64 -fsanitize=address
INCLUDE = -I include -I /usr/local/opt/readline/include -I /usr/local/Cellar/readline/8.2.10/include
LDFLAGS = -L /usr/local/opt/readline/lib -L /usr/local/Cellar/readline/8.2.10/lib
MAKE = make -C
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
LFLAGS = -L ${LIBFT_PATH} -lft -lreadline

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(LIBFT):
	${MAKE} ${LIBFT_PATH} all

$(NAME): $(LIBFT) ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LDFLAGS} ${LFLAGS} -o ${NAME}

clean:
	${MAKE} ${LIBFT_PATH} clean
	${RM} ${OBJS}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME}

re: fclean all

leaks: readline.supp
	valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --log-file=output.log ./minishell

readline.supp:
	echo "{" > readline.supp
	echo "    leak readline" >> readline.supp
	echo "    Memcheck:Leak" >> readline.supp
	echo "    ..." >> readline.supp
	echo "    fun:readline" >> readline.supp
	echo "}" >> readline.supp
	echo "{" >> readline.supp
	echo "    leak add_history" >> readline.supp
	echo "    Memcheck:Leak" >> readline.supp
	echo "    ..." >> readline.supp
	echo "    fun:add_history" >> readline.supp
	echo "}" >> readline.supp

.SILENT:

.PHONY: all clean fclean re
