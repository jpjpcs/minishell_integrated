/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:06:54 by luide-so          #+#    #+#             */
/*   Updated: 2024/06/02 18:52:36 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

// void	ft_free_array(char **array)
// {
// 	int	i;

// 	if (!array)
// 		return ;
// 	i = 0;
// 	while (array[i])
// 	{
// 		free(array[i]);
// 		array[i] = NULL; // Garantir que o ponteiro não seja usado novamente
// 		i++;
// 	}
// 	free(array);
// 	array = NULL; // Garantir que o ponteiro não seja usado novamente
// }