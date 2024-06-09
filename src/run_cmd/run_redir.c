/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:38:07 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:38:09 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	expand_file(t_shell *shell, char **file)
{
	int	len;

	expand_arg(shell, file);
	len = ft_strlen(*file);
	arg_insert_null(*file);
	trim_quotes(*file, &len);
	return (1);
}

void	run_redir(t_shell *shell, t_redir *cmd)
{
	int	fd;
	int	original_fd;

	original_fd = dup(cmd->fd);
	fd = -2;
	if (expand_file(shell, &cmd->file))
		fd = open(cmd->file, cmd->mode, 0644);
	if (fd == -1)
		print_error(shell, cmd->file, strerror(errno), 1);
	else if (shell->status == CONTINUE)
	{
		dup2(fd, cmd->fd);
		close(fd);
		run_cmd(shell, cmd->cmd);
	}
	check(dup2(original_fd, cmd->fd), "dup2 error", 1);
}
