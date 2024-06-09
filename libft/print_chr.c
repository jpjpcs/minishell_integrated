/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:36:48 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:36:50 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_chr(char c, int *flags)
{
	int	i;

	i = 0;
	if (flags[3])
	{
		write(1, &c, 1);
		while (i < flags[7] - 1)
			i += write(1, " ", 1);
	}
	else
	{
		while (i < flags[7] - 1)
			i += write(1, " ", 1);
		write(1, &c, 1);
	}
	return (1 + i);
}
