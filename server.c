/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:41:32 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/01/04 12:50:24 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftX/libft.h"
#include <signal.h>

int	g_i;

static	char	bin_to_dec(char *binary, int length)
{
	int		decimal;
	int		weight;
	char	chr;

	decimal = 0;
	weight = 1;
	binary += length - 1;
	weight = 1;
	while (length)
	{
		if (*binary == '1')
			decimal += weight;
		weight *= 2;
		binary--;
		length--;
	}
	chr = decimal;
	write (1, &chr, 1);
	return (1);
}

static	void	sig_handler(int sig)
{
	static char	bcode[9];

	if (sig == SIGUSR2)
		bcode[g_i] = '0';
	else if (sig == SIGUSR1)
		bcode[g_i] = '1';
	if (g_i == 7)
	{
		bcode[8] = '\0';
		bin_to_dec(bcode, 8);
		g_i = -1;
	}
	g_i++;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		;
	return (0);
}
