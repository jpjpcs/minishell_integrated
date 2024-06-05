/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp2_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:29:21 by joaosilva         #+#    #+#             */
/*   Updated: 2024/06/05 20:26:25 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (!lst || !new)
		return (false);
	if (!*lst)
	{
		*lst = new;
		return (true);
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (true);
}

// Função para criar um nó. É semelhante à ft_lstnew,
//mas além do valor/conteúdo, tb tem o visivel,
t_env	*env_lstnew(char *key, char *value, int visible)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->visible = visible;
	new->next = NULL;
	return (new);
}

void	add_node_to_envp_sorted_list(t_shell *shell, char *key, char *value,
		int visible)
{
	t_env *new_node;
	t_env **current;
	
    new_node = env_lstnew(key, value, visible);
    if (!new_node)
		return ;
	current = &shell->env_list_sorted;
	while (*current)
	{
		if(ft_strcmp(new_node->key, (*current)->key) < 0)
		{
			new_node->next = *current;
			*current = new_node;
			break ;
		}
		else
			current = &(*current)->next;
	}
	if (!*current)
		*current = new_node;
}

void	add_node_to_envp_unsorted_list(t_shell *shell, char *key, char *value,
		int visible)
{
	t_env *new_node;

    new_node = env_lstnew(key, value, visible);
    if (!new_node)
        return ;
    if (env_lstadd_back(&shell->env_list_unsorted, new_node))
        shell->envp_size++;
    convert_envp_to_char(shell);
}

// Função semelhante à lstadd_back,
//	para adicionar um novo nó ao final da lista 
// ligada de variáveis de ambiente.
void	create_update_envp_lists(t_shell *shell, char *key, char *value,
		int visible)
{
	add_node_to_envp_unsorted_list(shell, key, value,visible);
	add_node_to_envp_sorted_list(shell, key, value,visible);

}

