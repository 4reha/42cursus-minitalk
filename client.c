/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:51:02 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/01/09 09:34:33 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftX/libft.h"
#include <signal.h>

static void	send_char(int pid, char c, int *r)
{
	int		bit;

	bit = 8;
	if (pid != -1)
	{
		while (--bit != -1)
		{
			if (c & (1 << bit))
				*r = kill(pid, SIGUSR1);
			else
				*r = kill(pid, SIGUSR2);
			usleep(500);
		}
	}
	return (0);
}

int	main(int argc, char*argv[])
{
	int		pid;
	int		i;
	char	*str;
	int		r;

	r = 1;
	if (argc == 3)
	{
		i = -1;
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (argv[2][++i])
		{
			send_char(pid, argv[2][i], &r);
			usleep(300);
		}
		if (r == 0)
			ft_printf("Data has been recived successfully √\n");
		else
			ft_printf("Data has been lost :/");
	}
	else
		ft_printf("Usage error!: ./client {PID} 'Message'");
	return (0);
}
