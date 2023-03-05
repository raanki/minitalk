/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:10:52 by ranki             #+#    #+#             */
/*   Updated: 2023/03/04 19:59:50 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_message[5000000];

void	ft_octet(int *i, char *byte, int *start, siginfo_t *siginfo)
{
	int	check_kill;

	check_kill = 1;
	g_message[*i] = *byte;
	*byte = 0;
	if (g_message[*i] == '\0')
	{
		ft_printf("%s", g_message);
		*i = 0;
		*start = 0;
		check_kill = kill(siginfo->si_pid, SIGUSR2);
		signal_error(check_kill);
		return ;
	}
	(*i)++;
}

void	ft_handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	static char	byte;
	static int	bits_received;
	static int	i;
	static int	start;

	(void)context;
	if (start == 1)
	{
		if (sig == SIGUSR2)
			byte |= (1 << bits_received);
		bits_received++;
		if (bits_received == 8)
		{
			bits_received = 0;
			ft_octet(&i, &byte, &start, siginfo);
		}
		signal_error(kill(siginfo->si_pid, SIGUSR1));
	}
	else
	{
		start = 1;
		signal_error(kill(siginfo->si_pid, SIGUSR1));
	}
}

int	main(int ac, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (ac > 1)
	{
		ft_printf("\033[34;01mAttention : The server doesn't\033[00m\n");
		ft_printf("\033[34;01mneed any arguments\033[00m\n");
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_handle_signal;
	sa.sa_flags = SA_SIGINFO ;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("\033[32;01mServer PID : [\033[00m");
	ft_printf("\033[35;01m%d\033[00m", getpid());
	ft_printf("\033[32;01m]\033[00m\n");
	while (1)
		pause();
	return (0);
}
