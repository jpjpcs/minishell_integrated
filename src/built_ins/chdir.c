/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:39:00 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:39:02 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	ms_chdir(t_shell *shell, char *path)
{
	char	*tmp_pwd;

	if (!path)
		return (false);
	tmp_pwd = getcwd(NULL, 0);
	if (chdir(path) != 0)
	{
		free(tmp_pwd);
		return (false);
	}
	env_export(shell, "OLDPWD", tmp_pwd, 1);
	free(tmp_pwd);
	tmp_pwd = getcwd(NULL, 0);
	env_export(shell, "PWD", tmp_pwd, 1);
	free(tmp_pwd);
	return (true);
}
