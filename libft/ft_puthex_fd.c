/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:33:57 by crocha-s          #+#    #+#             */
/*   Updated: 2024/06/08 19:33:59 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned int num, const char c, int fd)
{
	if (num >= 16)
	{
		ft_puthex_fd(num / 16, c, fd);
		ft_puthex_fd(num % 16, c, fd);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', fd);
		else
			ft_putchar_fd(num - 33 + c, fd);
	}
}
