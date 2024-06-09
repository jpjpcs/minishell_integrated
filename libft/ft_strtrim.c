/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:36:01 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:36:03 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beguin;
	int		end;
	char	*c;

	end = ft_strlen(s1) - 1;
	beguin = 0;
	while (beguin <= end && ft_strchr(set, s1[beguin]))
		beguin++;
	if (beguin > end)
		return (ft_strdup(&s1[end + 1]));
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	c = (char *)malloc(sizeof(char) * (end - beguin + 1) + 1);
	if (!c)
		return (NULL);
	ft_strlcpy(c, &s1[beguin], (end - beguin + 1) + 1);
	return (c);
}
