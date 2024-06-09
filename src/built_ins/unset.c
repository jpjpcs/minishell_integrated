/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:39:35 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:39:37 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	valid_unset_var(t_shell *shell, char *arg)
{
	int	i;

	i = 0;
	if (!ft_isalpha(arg[i]) && arg[i] != '_')
		return (error_inside(shell, "unset: ", arg, 1));
	while (arg[++i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (error_inside(shell, "unset: ", arg, 1));
	}
	return (true);
}

char	*get_key(char *key, t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env_list_unsorted;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp->key);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ms_unset(t_shell *shell, t_exec *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[++i])
	{
		if (*cmd->argv[i] && valid_unset_var(shell, cmd->argv[i]))
		{
			if (get_key(cmd->argv[i], shell))
				env_rm(cmd->argv[i], shell);
		}
	}
	if (shell->status == CONTINUE)
		g_exit = 0;
}
