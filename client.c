/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:09:48 by ayasar            #+#    #+#             */
/*   Updated: 2024/12/15 11:22:45 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

static int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (result * sign < INT_MIN)
			return (0);
		if (result * sign > INT_MAX)
			return (-1);
	}
	return ((int)result * sign);
}

void	flag_handler(int signal)
{
	(void)signal;
	if (signal == SIGUSR1)
		g_flag = 1;
}

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
			;
		g_flag = 0;
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Wrong format!!!");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		ft_printf("Invalid PID");
		return (1);
	}
	signal(SIGUSR1, flag_handler);
	message = argv[2];
	while (*message)
		send_signal(pid, *message++);
	send_signal(pid, '\0');
	return (0);
}
