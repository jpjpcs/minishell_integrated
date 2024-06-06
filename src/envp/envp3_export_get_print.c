/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp3_export_get_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:28:33 by joaosilva         #+#    #+#             */
/*   Updated: 2024/06/06 22:47:08 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Esta função cria um novo nó para a lista ligada de variáveis de ambiente.
void	envp_print(t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env_list_unsorted;
	while (tmp)
	{
		if (tmp->visible)
			ft_printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

// Esta função retorna o valor de uma variável de ambiente 
// com base na chave fornecida.
char	*env_get(char *key, t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env_list_unsorted;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

// Esta função modifica o valor de uma variável de 
// ambiente com base na chave fornecida.
// Se a key não existir, cria através da create_update_envp_lists.
// Se a key existir, modifica o valor através da env_mod.
void	env_export(t_shell *shell, char *key, char *value, int visible)
{
	if (!env_get(key, shell))
		create_update_envp_lists(shell, key, value, visible);
	else if (env_get(key, shell) && visible)
		env_mod(shell, key, value);
}
