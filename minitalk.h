/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:05:34 by ranki             #+#    #+#             */
/*   Updated: 2023/03/04 19:50:17 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "ft_printf/ft_printf.h"

void	signal_error(int check_kill);
void	ft_putstr(const char *s);
int		ft_atoi(const char *s);
size_t	ft_strlen(const char *d);
void	ft_check_pid(char *pid);
char	*ft_strcpy(char *dst, const char *src);
#endif
