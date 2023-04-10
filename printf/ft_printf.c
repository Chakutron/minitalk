/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:29:27 by mchiboub          #+#    #+#             */
/*   Updated: 2023/02/24 13:28:44 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_str(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr2("cspdiuxX%", str[i]) < 0)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	write_flags(char str, va_list parameters)
{
	int	c;

	c = 0;
	if (str == 'c')
		c += write_c(va_arg(parameters, int));
	else if (str == 's')
		c += write_s(va_arg(parameters, char *));
	else if (str == 'p')
		c += write_p((unsigned long long)va_arg(parameters, void *));
	else if (str == 'd')
		c += ft_putnbr(va_arg(parameters, int));
	else if (str == 'i')
		c += ft_putnbr(va_arg(parameters, int));
	else if (str == 'u')
		c += ft_putnbr(va_arg(parameters, unsigned int));
	else if (str == 'x')
		c += write_x(va_arg(parameters, unsigned int), 0);
	else if (str == 'X')
		c += write_x(va_arg(parameters, unsigned int), 1);
	else if (str == '%')
		c += write_c('%');
	return (c);
}

static int	work_str(const char *str, va_list parameters)
{
	int			c;
	size_t		i;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			c += write_c(str[i]);
		else
		{
			i++;
			c += write_flags(str[i], parameters);
		}
		i++;
	}
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list				parameters;
	int					counter;

	va_start(parameters, str);
	if (!check_str(str))
		return (-1);
	counter = work_str(str, parameters);
	va_end(parameters);
	return (counter);
}
