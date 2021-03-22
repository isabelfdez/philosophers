/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:47:43 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/22 19:09:11 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	ft_atoi(const char *str)
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

static void	ft_putendl_fd(char *s, int fd)
{
	int	i;

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

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(t_state *p, char *str)
{
	if (p)
	{
		sem_unlink(SEM_DEAD);
		sem_unlink(SEM_WRITE);
		sem_unlink(SEM_CHOPSTICKS);
		free(p);
	}
	if (str)
		ft_putendl_fd(str, 1);
	return (0);
}

sem_t	*ft_create_sem(char const *str, int value)
{
	sem_unlink(str);
	return (sem_open(str, O_CREAT | O_EXCL, 0644, value));
}
