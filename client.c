/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:45:06 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/11 14:54:40 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ready = 1;

void	char2bin(unsigned int nbr, char *str)
{
	int		i;
	int		temp;

	if (nbr / 4294967040 == 1)
		nbr -= 4294967040;
	i = 7;
	while (i >= 0)
	{
		temp = nbr / ft_recursive_power(2, i);
		str[7 - i] = 48 + temp;
		if (temp)
			nbr -= ft_recursive_power(2, i);
		i--;
	}
	str[8] = '\0';
}

void	handler(int sig)
{
	if (sig == SIGUSR2)
		g_ready = 2;
	else if (sig == SIGUSR1)
		g_ready = 1;
}

void	client_work(char *strbin, int pid, int i)
{
	while (i < 8)
	{
		g_ready = 0;
		if (strbin[i] == '0')
			kill(pid, SIGUSR1);
		else if (strbin[i] == '1')
			kill(pid, SIGUSR2);
		while (1)
		{
			if (g_ready == 1)
				break ;
			else if (g_ready == 2)
			{
				ft_printf("Message received.\n");
				break ;
			}
			usleep(1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	strbin[9];
	int		j;

	if (argc != 3)
	{
		ft_printf("USAGE: ./client <Server PID> \"message\"\n");
		exit (0);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	j = 0;
	while (1)
	{
		char2bin(argv[2][j], &strbin[0]);
		client_work(&strbin[0], pid, 0);
		if (argv[2][j] == '\0')
			break ;
		j++;
	}
	return (0);
}
