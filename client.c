/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:01:03 by iharile           #+#    #+#             */
/*   Updated: 2021/12/21 20:16:58 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + *str - '0';
		if (res > 9223372036854775807 && sign == 1)
			return (-1);
		else if (res > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}	
	return (res * sign);
}

void	convert_to_binary(char *str, pid_t a)
{
	int				i;
	int				j;
	unsigned char	c;

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
			}
			else
				kill (a, SIGUSR2);
			usleep(100);
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
		a = atoi(argv[1]);
		convert_to_binary(argv[2], a);
	}
	return (0);
}
