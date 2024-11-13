/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:02:36 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/01/24 14:52:11 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*manage_bits(char c)
{
	int		i;
	char	*octet;

	i = 8;
	octet = malloc(8);
	octet[i--] = 0;
	while (i >= 0)
	{
		if (c % 2 == 1)
			octet[i] = '1';
		else
			octet[i] = '0';
		c /= 2;
		i--;
	}
	return (octet);
}

void	manage_str(char *str, pid_t PID)
{
	size_t	i;
	char	*rec;
	char	*old_rec;

	i = 0;
	rec = malloc(sizeof(char *) * strlen(str) + 1);
	while (str[i])
	{
		old_rec = rec;
		rec = ft_strjoin(rec, manage_bits(str[i]));
		free(old_rec);
		i++;
	}
	i = 0;
	while (rec[i] != 0)
	{	
		if (rec[i] == '1')
			kill(PID, SIGUSR1);
		else if (rec[i] == '0')
			kill(PID, SIGUSR2);
		i++;
		usleep (80);
	}	
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (printf("allocation went wrong\n"));
	pid = ft_atoi(argv[1]);
	manage_str(argv[2], pid);
	return (0);
}
