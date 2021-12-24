/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:24:09 by iharile           #+#    #+#             */
/*   Updated: 2021/12/24 15:46:32 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	powof2(int rep)
{
	int	i;
	int	num;
	int	res;

	i = 1;
	num = 2;
	res = num;
	if (rep == 0)
		return (i);
	while (i < rep)
	{
		res *= num;
		i++;
	}
	return (res);
}

void	ft_swap(int *tab)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 7;
	while (i < 4)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		i++;
		j--;
	}
}

void	handler(int n)
{
	static int	i = 0;
	int			num;
	int			j;
	int			tab[8];
	char		wd;

	num = 0;
	if (SIGUSR1 == n)
		tab[i++] = 1;
	else if (SIGUSR2 == n)
		tab[i++] = 0;
	if (i == 8)
	{
		j = 0;
		ft_swap(&tab[0]);
		while (j <= 7)
		{
			if (tab[j] == 1)
				num += powof2(j);
			j++;
		}
		i = 0;
		wd = num;
		write (1, &wd, 1);
	}
}

void	ft_putnbr(long n)
{
	int		i;
	char	c;

	i = 0;
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + 48;
	write (1, &c, 1);
}

int	main(void)
{
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	write(1, "The Server IS :", 15);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
