/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:37:15 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:37:17 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_left(char *s, int *flags)
{
	int	i;

	i = 0;
	ft_putstr_fd(s, 1);
	free(s);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i);
}

static int	str_right(char *s, int *flags)
{
	int	i;

	i = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	ft_putstr_fd(s, 1);
	free(s);
	return (i);
}

int	print_str(char *s, int *flags)
{
	int	len;

	if (flags[5] && flags[6] < 5 && !s)
		return (print_str("", flags));
	if (!s)
		return (print_str("(null)", flags));
	len = (int)ft_strlen(s);
	if (flags[5] && len > flags[6])
		len = flags[6];
	s = ft_substr(s, 0, len);
	flags[7] -= len;
	if (flags[3])
		return (len + str_left(s, flags));
	else
		return (len + str_right(s, flags));
}
