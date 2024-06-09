/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:38:40 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:38:42 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_exec(t_exec *exec)
{
	if (!exec)
		return ;
	if (exec->argv[0])
		free(exec->argv[0]);
	free(exec);
	exec = NULL;
}

static void	free_redir(t_redir *redir)
{
	if (!redir)
		return ;
	free_cmd(redir->cmd);
	if (redir->file)
		free(redir->file);
	free(redir);
	redir = NULL;
}

static void	free_here(t_here *here)
{
	if (!here)
		return ;
	free_cmd(here->cmd);
	if (here->eof)
		free(here->eof);
	free(here);
	here = NULL;
}

static void	free_pipe(t_pipe *pipe)
{
	if (!pipe)
		return ;
	free_cmd(pipe->left);
	free_cmd(pipe->right);
	free(pipe);
	pipe = NULL;
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	else if (cmd->type == PIPE)
		free_pipe((t_pipe *)cmd);
	else if (cmd->type == HERE_DOC)
		free_here((t_here *)cmd);
	else if (cmd->type == REDIR)
		free_redir((t_redir *)cmd);
	else if (cmd->type == EXEC)
		free_exec((t_exec *)cmd);
}
