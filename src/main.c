/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:07:27 by joaosilva         #+#    #+#             */
/*   Updated: 2024/06/07 18:45:28 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			g_exit;

// Função para mostrar o prompt do shell
static char	*show_prompt(void)
{
	char	*cwd;
	char	*prompt;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("Error getting current working directory");
		return (NULL);
	}
	prompt = ft_strjoin(PROMPT_BEGIN, cwd);
	free(cwd);
	cwd = ft_strjoin(prompt, PROMPT_END);
	free(prompt);
	if (!cwd)
	{
		perror("Error creating shell prompt");
		return (NULL);
	}
	return (cwd);
}

// Função para obter o prompt do shell
static char	*get_prompt(t_shell *shell)
{
	shell->prompt = show_prompt();
	if (!shell->prompt)
	{
		perror("Error creating shell prompt");
		return (NULL);
	}
	shell->line = readline(shell->prompt);
	free(shell->prompt);
	return (shell->line);
}

// Função para correr o loop principal
static int	to_run(t_shell *shell)
{
	signal_handler(SIGRESTORE);
	shell->status = STOP;
	shell->line = get_prompt(shell);
	if (shell->line && process_line(shell))
	{
		if (parse_cmd(shell))
		{
			signal_handler(SIGPIPE);
			run_cmd(shell, shell->cmd);
		}
		free_cmd(shell->cmd);
	}
	free(shell->line);
	return (shell->status);
}

// Função para inicializar as variáveis do shell
static int	init_shell_variables(t_shell *shell, char **envp)
{
	*shell = (t_shell){0};
	convert_envp_to_linked_lists(envp, shell);
	convert_envp_to_char(shell);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argv;
	if (!init_shell_variables(&shell, envp))
		return (0);
	if (argc != 1)
	{
		printf("Minishell need no arguments. Try './minishell'.\n");
		return (0);
	}
	else
		printf("\nMinishell 1.0: Authors: jode-jes, crocha-s.\n");
	while (to_run(&shell))
		;
	clear_history();
	ft_envlstclear(shell.env_list_unsorted, free);
	ft_envlstclear(shell.env_list_sorted, free);
	if (shell.envp_char)
		ft_free_array(shell.envp_char);
	if (isatty(STDIN_FILENO))
		ft_putendl_fd("exit", 2);
	return (g_exit);
}
