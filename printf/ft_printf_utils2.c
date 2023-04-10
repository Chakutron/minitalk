/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:29:27 by mchiboub          #+#    #+#             */
/*   Updated: 2023/02/24 12:20:01 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(long long int nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		i++;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		ft_write_int(nb % 10);
		i++;
	}
	else
	{
		ft_write_int(nb);
		i++;
	}
	return (i);
}

size_t	ft_putnbr_base_pointer(unsigned long long nbr, char *base)
{
	unsigned long long	b;
	size_t				i;

	i = 0;
	b = ft_strlen(base);
	if (nbr >= b)
	{
		i += ft_putnbr_base_pointer(nbr / b, base);
		i += ft_putnbr_base_pointer(nbr % b, base);
	}
	else
	{
		write(1, &base[nbr], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbr_base_hex(long long nbr, char *base)
{
	long long	b;
	size_t		i;

	i = 0;
	b = ft_strlen(base);
	if (nbr >= b)
	{
		i += ft_putnbr_base_hex(nbr / b, base);
		i += ft_putnbr_base_hex(nbr % b, base);
	}
	else
	{
		write(1, &base[nbr], 1);
		i++;
	}
	return (i);
}
