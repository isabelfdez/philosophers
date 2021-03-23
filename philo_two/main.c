/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:12:45 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/23 16:24:23 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	check_arguments(int argc, char **argv)
{
	if (argc < 5)
	{
		write(1, "Too few arguments\n", ft_strlen("Too few arguments\n"));
		return (0);
	}
	if (argc > 6)
	{
		write(1, "Too many arguments\n", ft_strlen("Too many arguments\n"));
		return (0);
	}
	if (ft_atoi(argv[1]) <= 1 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0)
	{
		write(1, "Invalid arguments\n", ft_strlen("Invalid arguments\n"));
		return (0);
	}
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
	{
		write(1, "Invalid arguments\n", ft_strlen("Invalid arguments\n"));
		return (0);
	}
	return (1);
}

static int	init_sem(t_state *p)
{
	p->chopsticks = ft_create_sem(SEM_CHOPSTICKS, p->num);
	p->write = ft_create_sem(SEM_WRITE, 1);
	p->dead = ft_create_sem(SEM_DEAD, 0);
	return (1);
}

static int	init(t_state *p)
{
	int		i;

	i = -1;
	p->philos = malloc(sizeof(t_philo) * p->num);
	if (!p->philos)
		return (0);
	while (++i < p->num)
	{
		p->philos[i].pos = i;
		p->philos[i].is_eating = 0;
		p->philos[i].lfork = i;
		p->philos[i].rfork = (i + 1) % p->num;
		p->philos[i].eat_count = 0;
		p->philos[i].state = p;
	}
	return (init_sem(p));
}

int	main(int argc, char **argv)
{
	t_state	*p;

	if (!check_arguments(argc, argv))
		return (-1);
	p = malloc(sizeof(t_state));
	p->num = ft_atoi(argv[1]);
	p->tdie = ft_atoi(argv[2]);
	p->teat = ft_atoi(argv[3]);
	p->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
		p->meals = ft_atoi(argv[5]);
	else
		p->meals = 0;
	if (!init(p))
		return (ft_error(NULL, "Memory allocation error\n"));
	if (!init_threads(p))
		return (ft_error(p, "Unexpected error\n"));
	sem_wait(p->dead);
	ft_error(p, NULL);
	return (0);
}
