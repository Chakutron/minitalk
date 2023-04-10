/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:45:06 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/08 18:51:35 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

char	*ft_strcat2(char *str, char c)
{
	int		i;
	int		len;
	char	*str2;

	len = ft_strlen(str);
	if (c)
	{
		str2 = malloc(len + 2);
		i = 0;
		while (str[i])
		{
			str2[i] = str[i];
			i++;
		}
		str2[len] = c;
		str2[len + 1] = '\0';
		free(str);
		return (str2);
	}
	return (str);
}
