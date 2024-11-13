/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_alter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:55:04 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/01/24 14:52:08 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	val;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else
			i++;
	}
	val = 0;
	while (str[i] >= '0' && str[i] <= '9')
		val = val * 10 + (str[i++] - '0');
	return (val * sign);
}

size_t	strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s1 != 0)
	{
		new_str[i++] = *s1++;
	}
	while (*s2 != 0)
	{
		new_str[i++] = *s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}
