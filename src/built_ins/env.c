/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:56:55 by luide-so          #+#    #+#             */
/*   Updated: 2024/06/06 22:56:19 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ms_env(t_shell *shell, t_exec *cmd)
{
	if (cmd->argv[2])
		print_error(shell, "env", "too many arguments", 2);
	else
	{
		if (env_get("PATH", shell))
			envp_print(shell);
		else
			print_error(shell, cmd->argv[0], "No such file or directory", 127);
	}
	if (shell->status == CONTINUE)
		g_exit = 0;
}
