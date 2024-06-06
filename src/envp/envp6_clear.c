/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp6_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:11:04 by jode-jes          #+#    #+#             */
/*   Updated: 2024/06/06 22:14:06 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_envlstclear(t_env *lst, void (*del)(void *))
{
	t_env	*tmp;

	if (!lst || !del)
		return ;
	while (lst)
	{
		tmp = (lst)->next;
		ft_envlstdelone(lst, del);
		lst = tmp;
	}
}
