/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:10:43 by ranki             #+#    #+#             */
/*   Updated: 2023/03/04 20:07:33 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_message[5000000];

void	handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	static int	nb_byte;
	static int	indice;

	(void)context;
	if (sig == SIGUSR1)
	{
		if (g_message[indice] & 1 << nb_byte)
			signal_error(kill(siginfo->si_pid, SIGUSR2));
		else
			signal_error(kill(siginfo->si_pid, SIGUSR1));
		nb_byte++;
		if (nb_byte == 8)
		{
			indice++;
			nb_byte = 0;
		}
	}
	else
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc == 3)
	{
		ft_check_pid(argv[1]);
		sigemptyset(&sa.sa_mask);
		sa.sa_sigaction = handle_signal;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		ft_strcpy(g_message, argv[2]);
		signal_error(kill(ft_atoi(argv[1]), SIGUSR1));
		while (1)
			pause();
	}
	else
	{
		if (argc > 3)
			ft_printf("\033[31;01mERROR (): Too many arguments\033[00m\n");
		if (argc < 3)
			ft_printf("\033[31;01mERROR (): Not enough arguments\033[00m\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
