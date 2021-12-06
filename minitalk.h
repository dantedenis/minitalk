/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:26:32 by bstrong           #+#    #+#             */
/*   Updated: 2021/11/25 11:43:17 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft.h"

# define SLEEP 100

void	send_message(int pid, unsigned char ch);
void	print_message(int signal, siginfo_t *siginfo, void *context);
void	print_pid(int process_id);
void	print_sent(char *str);

#endif
