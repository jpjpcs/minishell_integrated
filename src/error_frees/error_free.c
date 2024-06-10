/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:37:39 by joaosilva         #+#    #+#             */
/*   Updated: 2024/06/10 16:21:17 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_exit(t_shell *shell)
{
	if (shell->line)
		free(shell->line);
	free_cmd(shell->cmd);
	ft_envlstclear(shell->env_list_unsorted, free);
	ft_envlstclear(shell->env_list_sorted, free);
	if (shell->envp_char)
		ft_free_array(shell->envp_char);
	exit(g_exit);
}

// Esta função imprime uma mensagem de erro de sintaxe no stderr.
int	print_error_syntax(t_shell *shell, char *msg, int exit)
{
	ft_putstr_fd(ERROR_TITLE, STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	if (*msg == '\0')
		ft_putstr_fd("newline", STDERR_FILENO);
	else
		ft_putchar_fd(*msg, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	shell->status = RESTORE;
	g_exit = exit;
	return (1);
}

// Esta função imprime uma mensagem de erro no stderr.
int	print_error(t_shell *shell, char *msg, char *msg2, int exit)
{
	ft_putstr_fd(ERROR_TITLE, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (msg2)
		ft_putstr_fd(": ", STDERR_FILENO);
	else
		ft_putchar_fd('\n', STDERR_FILENO);
	ft_putendl_fd(msg2, STDERR_FILENO);
	shell->status = RESTORE;
	g_exit = exit;
	return (1);
}

int	error_inside(t_shell *shell, char *cmd, char *arg, int error_code)
{
	char	*err;

	err = ft_strjoin(cmd, arg);
	print_error(shell, err, "not a valid identifier", error_code);
	free(err);
	return (0);
}
