/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:31:12 by bstrong           #+#    #+#             */
/*   Updated: 2021/11/25 13:14:27 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, unsigned char ch)
{
	uint8_t	i;

	i = 0x80;
	while (i)
	{
		if (ch & i)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i >>= 1;
		pause();
		usleep(SLEEP);
	}
}

void	print_message(int signal, siginfo_t *siginfo, void *context)
{
	static unsigned char	ch;
	static int				i;
	static pid_t			client_pid;

	(void)context;
	if (client_pid != siginfo->si_pid)
	{
		client_pid = siginfo->si_pid;
		i = 0;
	}
	ch <<= 1;
	ch |= (signal == SIGUSR2);
	if (++i == 8)
	{
		if (!ch)
		{
			kill(client_pid, SIGUSR2);
			return ;
		}
		write(1, &ch, 1);
		i = 0;
		ch = 0;
	}
	usleep(SLEEP);
	kill(client_pid, SIGUSR1);
}

void	print_pid(int process_id)
{
	ft_putstr_fd("\n✋PID: \x1b[34m", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putstr_fd("\x1b[0m use it🙌 👉\x1b[32m./client \x1b[34m[PID] [MESSAGE]👈 \
	\n\x1b[36m INCOMING MESSAGE:\n\n\x1b[0m", 1);
}

void	print_sent(char *str)
{
	ft_putstr_fd("\nSent:\033[45m\t\t", 1);
	ft_putnbr_fd(ft_strlen(str), 1);
	ft_putstr_fd("\x1b[0m\n", 1);
}
