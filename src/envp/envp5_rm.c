/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp5_rm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:42:12 by jode-jes          #+#    #+#             */
/*   Updated: 2024/06/05 20:27:47 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_envlstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst)
	{
		del(lst->key);
		if (lst->value)
			del(lst->value);
		del(lst);
		lst = NULL;
	}
}

bool	env_rm_sorted(char *key, t_shell *shell)
{
	t_env	*tmp;
	t_env	*tmp_last;

	tmp = shell->env_list_sorted;
	tmp_last = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			if (tmp_last)
				tmp_last->next = tmp->next;
			if (tmp == shell->env_list_sorted)
				shell->env_list_sorted = tmp->next;
			ft_envlstdelone(tmp, free);
			return (true);
		}
		tmp_last = tmp;
		tmp = tmp->next;
	}
	return (false);
}

bool	env_rm_unsorted(char *key, t_shell *shell)
{
	t_env	*tmp;
	t_env	*tmp_last;

	tmp = shell->env_list_unsorted;
	tmp_last = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			if (tmp_last)
				tmp_last->next = tmp->next;
			if (tmp == shell->env_list_unsorted)
				shell->env_list_unsorted = tmp->next;
			ft_envlstdelone(tmp, free);
			shell->envp_size--;
			convert_envp_to_char(shell);
			return (true);
		}
		tmp_last = tmp;
		tmp = tmp->next;
	}
	return (false);
}

void	env_rm(char *key, t_shell *shell)
{
	env_rm_unsorted(key, shell);
	env_rm_sorted(key, shell);
}
