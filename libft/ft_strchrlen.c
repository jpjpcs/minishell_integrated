/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:34:35 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:34:37 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchrlen(const char *str, char *set)
{
	size_t	i;

	i = 0;
	while (str && str[i] && !ft_strchr(set, str[i]))
		i++;
	return (i);
}
