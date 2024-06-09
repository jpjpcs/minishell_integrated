/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:34:23 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:34:25 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int	count;
	int	i;
	int	old_i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i])
		{
			if (s[i] != c)
				break ;
			i++;
		}
		old_i = i;
		while (s[i])
		{
			if (s[i] == c)
				break ;
			i++;
		}
		if (old_i < i)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ar = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!ar)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			ar[j++] = ft_substr(s + i, 0, ft_strclen(s + i, c));
			if (!ar[j - 1])
				return (NULL);
			i += ft_strlen(ar[j - 1]);
		}
	}
	ar[j] = NULL;
	return (ar);
}
