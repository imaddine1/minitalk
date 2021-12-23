/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:01:03 by iharile           #+#    #+#             */
/*   Updated: 2021/12/23 10:47:12 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}	
	return (res * sign);
}

void	convert_to_binary(char *str, pid_t a)
{
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			if (c >= (1 << j))
			{
				c = c - (1 << j);
				kill (a, SIGUSR1);
				usleep(150);
			}
			else
			{
				kill (a, SIGUSR2);
				usleep(150);
			}
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	a;

	if (argc == 3)
	{
		a = ft_atoi(argv[1]);
		convert_to_binary(argv[2], a);
	}
	return (0);
}
