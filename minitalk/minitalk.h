/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:52:37 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/01/24 14:52:09 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

int		ft_atoi(const char *the_string);
size_t	strlen(const char *str);
void	convert_bin_dec(char *str);
int		send_pid(pid_t pid);
char	*ft_strjoin(char const *s1, char const *s2);
void	manage_str(char *str, pid_t PID);
void	sig_handler(int signal);
char	*manage_bits(char c);

#endif