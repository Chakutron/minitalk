/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:19:57 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/10 18:16:12 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <limits.h>

char	g_strbin[9];

unsigned long long	bin2char(char *strbin)
{
	int					i;
	unsigned long long	num;

	i = 0;
	num = 0;
	while (i < 8)
	{
		if (strbin[i] == '1')
			num += ft_recursive_power(2, 7 - i);
		i++;
	}
	return (num);
}

void	work_the_signal(int bits, int client_pid, u_int64_t num, char **str)
{
	bits++;
	g_strbin[bits] = '\0';
	if (bits == 8)
	{
		num = bin2char(g_strbin);
		*str = ft_strcat2(*str, num);
		g_strbin[0] = '\0';
		if (num == '\0')
		{
			kill(client_pid, SIGUSR2);
			*str = ft_strcat2(*str, '\n');
			write(1, *str, ft_strlen(*str));
			free(*str);
			*str = NULL;
		}
		else
			kill(client_pid, SIGUSR1);
	}
	else
		kill(client_pid, SIGUSR1);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	unsigned long long	num;
	int					bits;
	static char			*str = NULL;

	(void)context;
	num = 0;
	bits = 0;
	if (str == NULL)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		bits = ft_strlen(g_strbin);
		if (sig == SIGUSR1)
			g_strbin[bits] = '0';
		else if (sig == SIGUSR2)
			g_strbin[bits] = '1';
		work_the_signal(bits, info->si_pid, num, &str);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	g_strbin[0] = '\0';
	pid = getpid();
	ft_printf("PID = %i\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "SIGACTION ERROR\n", 16);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "SIGACTION ERROR\n", 16);
	while (1)
		usleep(1);
	return (0);
}
