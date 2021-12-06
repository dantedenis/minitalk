/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:21:03 by bstrong           #+#    #+#             */
/*   Updated: 2021/11/25 10:34:04 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sig_act;

	print_pid(getpid());
	sig_act.sa_sigaction = print_message;
	sig_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig_act, NULL) == -1
		|| sigaction(SIGUSR2, &sig_act, NULL) == -1)
		write(2, "SIGERROR!\n", 11);
	while (1)
		pause();
	return (0);
}
