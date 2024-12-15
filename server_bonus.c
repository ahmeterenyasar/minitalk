/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:51:04 by ayasar            #+#    #+#             */
/*   Updated: 2024/12/15 10:52:25 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	bit = 0;
	static int	i = 0;

	(void)ucontext;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == '\0')
		{
			ft_printf("\nSignal received from PID: %d\n",
				info->si_pid);
		}
		else
		{
			ft_printf("%c", i);
		}
		bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = ft_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_printf("Error: sigaction sigusr1");
		return (1);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_printf("Error: sigaction sigusr2");
		return (1);
	}
	ft_printf("PID: %d\n", getpid());
	ft_printf("Waiting for signals...\n");
	while (1)
	{
		pause();
	}
	return (0);
}
