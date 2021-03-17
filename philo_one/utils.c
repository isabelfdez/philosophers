/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:47:43 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/17 19:40:36 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		    ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		nb;

	i = 0;
	neg = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		nb = nb * (-1);
	return (nb);
}

// Habrá que hacer una función distinta cuando haya que matar mutex

static void ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_error(t_state *p, char *str)
{
	if (p)
		free(p);
	if (str)
		ft_putendl_fd(str, 1);
	return (0);
}

struct timeval	sum_time(struct timeval a, suseconds_t b)
{
	struct timeval	c;

	c.tv_usec = b + a.tv_usec;
	if (c.tv_usec < 1000000)
		c.tv_sec = a.tv_sec;
	else
	{
		c.tv_sec = a.tv_sec + 1;
		c.tv_usec = c.tv_usec - 1000000;
	}
	return (c);
}

suseconds_t		takeoff_time(struct timeval a, struct timeval b)
{
	suseconds_t	aux;

	if (a.tv_sec == b.tv_sec)
		return (a.tv_usec - b.tv_usec);
	else
	{
		aux = a.tv_usec - b.tv_usec;
		return (aux + (a.tv_sec - b.tv_sec) * 1000000);
	}
}
