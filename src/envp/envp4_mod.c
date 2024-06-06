/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp4_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:17:37 by jode-jes          #+#    #+#             */
/*   Updated: 2024/06/05 20:18:38 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	env_mod_sorted_list(t_shell *shell, char *target, char *new_value)
{
	t_env	*tmp_sorted;

	tmp_sorted = shell->env_list_sorted;
	while (tmp_sorted)
	{
		if (ft_strcmp(target, tmp_sorted->key) == 0)
		{
			free(tmp_sorted->value);
			tmp_sorted->value = ft_strdup(new_value);
			tmp_sorted->visible = 1;
			return (true);
		}
		tmp_sorted = tmp_sorted->next;
	}
	return (false);
}

bool	env_mod_unsorted_list(t_shell *shell, char *target, char *new_value)
{
	t_env	*tmp_unsorted;

	tmp_unsorted = shell->env_list_unsorted;
	while (tmp_unsorted)
	{
		if (ft_strcmp(target, tmp_unsorted->key) == 0)
		{
			free(tmp_unsorted->value);
			tmp_unsorted->value = ft_strdup(new_value);
			tmp_unsorted->visible = 1;
			return (true);
		}
		tmp_unsorted = tmp_unsorted->next;
	}
	return (false);
}

bool	env_mod(t_shell *shell, char *target, char *new_value)
{
	env_mod_unsorted_list(shell, target, new_value);
	env_mod_sorted_list(shell, target, new_value);
	return (false);
}
