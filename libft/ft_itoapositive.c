/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoapositive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:32:11 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:32:13 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoapositive(long long n)
{
	char		*c;
	bool		sign;
	long long	len;

	sign = n < 0;
	len = ft_intlen(n, 10);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (sign)
	{
		c[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len--)
	{
		c[len] = n % 10 + '0';
		n = n / 10;
	}
	return (c);
}
