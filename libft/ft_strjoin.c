/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:35:15 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:35:17 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	c = (char *)malloc(len * sizeof(char) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		c[i + j] = s2[j];
		j++;
	}
	c[i + j] = '\0';
	return (c);
}
