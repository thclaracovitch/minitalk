/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:19:20 by thclarac          #+#    #+#             */
/*   Updated: 2023/09/04 09:32:21 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	gestion(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	c |= (sig == SIGUSR2);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		if (!c)
		{
			ft_printf("\nAttente de message :\n");
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
		bit = 0;
	}
	usleep(200);
	c <<= 1;
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = gestion;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	ft_printf("Le PID du serveur est %d\n", getpid());
	ft_printf("Attente de message :\n");
	while (1)
	{
		sigaction(SIGUSR1, &sigact, 0);
		sigaction(SIGUSR2, &sigact, 0);
		pause ();
	}
	return (0);
}
