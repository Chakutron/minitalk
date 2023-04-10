/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:54:56 by mchiboub          #+#    #+#             */
/*   Updated: 2023/02/24 13:30:28 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
void	ft_write_int(int n);
int		ft_strchr2(const char *s, int c);
size_t	ft_putnbr(long long int nb);
size_t	ft_putnbr_base_pointer(unsigned long long nbr, char *base);
size_t	ft_putnbr_base_hex(long long nbr, char *base);
int		write_c(char c);
int		write_s(char *s);
int		write_p(unsigned long long p);
int		write_x(unsigned int x, int uppercase);

#endif
