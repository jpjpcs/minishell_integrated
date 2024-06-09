/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:32:06 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:32:07 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*c;
	bool	sign;
	int		len;

	sign = n < 0;
	len = ft_intlen(n, 10) + sign;
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (sign)
	{
		*c = '-';
		c[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len-- - sign)
	{
		c[len] = n % 10 + '0';
		n = n / 10;
	}
	return (c);
}
