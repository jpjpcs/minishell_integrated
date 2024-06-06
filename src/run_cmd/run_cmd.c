/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:13:21 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/06 22:53:59 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	run_cmd(t_shell *shell, t_cmd *cmd)
{
	if (cmd->type == EXEC && shell->exec_cmd == true)
		run_exec(shell, (t_exec *)cmd);
	else if (cmd->type == REDIR && shell->exec_cmd == true)
		run_redir(shell, (t_redir *)cmd);
	else if (cmd->type == HERE_DOC)
		run_heredoc(shell, (t_here *)cmd);
	else if (cmd->type == PIPE)
		run_pipe(shell, (t_pipe *)cmd);
}
