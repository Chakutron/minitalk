/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:29:27 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/07 15:20:16 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	write_s(char *s)
{
	int	c;

	if (!s)
		c = write(1, "(null)", 6);
	else
		c = write(1, s, ft_strlen(s));
	return (c);
}

int	write_p(unsigned long long p)
{
	int	c;

	if (!p)
	{
		write(1, "(nil)", 5);
		c = 5;
	}
	else
	{
		write(1, "0x", 2);
		c = 2 + ft_putnbr_base_pointer(p, "0123456789abcdef");
	}
	return (c);
}

int	write_x(unsigned int x, int uppercase)
{
	int	c;

	if (uppercase)
		c = ft_putnbr_base_hex(x, "0123456789ABCDEF");
	else
		c = ft_putnbr_base_hex(x, "0123456789abcdef");
	return (c);
}
