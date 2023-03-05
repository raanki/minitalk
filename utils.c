/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:54:32 by ranki             #+#    #+#             */
/*   Updated: 2023/03/04 19:24:48 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error(int check_kill)
{
	if (check_kill == -1)
	{
		ft_printf("\033[31;01mkill(): couldn't transmit bit\033[00m\n");
		exit(EXIT_FAILURE);
	}
}

size_t	ft_strlen(const char *d)
{
	size_t	cpt;

	cpt = 0;
	while (d[cpt])
		cpt++;
	return (cpt);
}

int	ft_atoi(const char *s)
{
	int		sign;
	int		n;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	while (s[i] == '\f' || s[i] == ' ' || s[i] == '\n'
		|| s[i] == '\t' || s[i] == '\v' || s[i] == '\r' )
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] != 0 && s[i] >= '0' && s[i] <= '9')
	{
		n = 10 * n + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

void	ft_check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
		{
			ft_printf("\033[31;01mERROR (): The PID doesn't\033[00m");
			ft_printf("\033[31;01m just have numbers\033[00m\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
