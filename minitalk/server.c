/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:36:37 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/01/24 14:52:06 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_pid(pid_t pid)
{
	pid = getpid();
	printf("pid: %i\n", pid);
	return (pid);
}

void	convert_bin_dec(char *str)
{
	int		i;
	int		j;
	char	add;
	int		pow;

	i = 0;
	while (i < 7)
	{
		add = 0;
		j = 7;
		pow = 1;
		while (j >= 0)
		{
			add += pow * (str[i + j] - '0');
			pow *= 2;
			j--;
		}
		write(1, &add, 1);
		i += 8;
	}
}

void	sig_handler(int signal)
{
	static char	*str;
	static int	idx = 0;

	if (str == NULL)
		str = malloc(8);
	if (signal == SIGUSR1)
		str[idx] = '1';
	else if (signal == SIGUSR2)
		str[idx] = '0';
	idx++;
	if (idx == 8)
	{	
		convert_bin_dec(str);
		idx = 0;
	}
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	pid = 0;
	send_pid(pid);
	while (1)
	{	
		pause();
	}
	return (0);
}
