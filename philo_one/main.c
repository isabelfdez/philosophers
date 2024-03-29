/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:42:04 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/22 19:14:54 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

static int	init_mutex(t_state *p)
{
	int		i;

	i = -1;
	pthread_mutex_init(&p->write_m, NULL);
	pthread_mutex_init(&p->dead_m, NULL);
	pthread_mutex_lock(&p->dead_m);
	p->fork_m = malloc(sizeof(pthread_mutex_t) * p->num);
	if (!p->fork_m)
		return (0);
	while (++i < p->num)
		pthread_mutex_init(&p->fork_m[i], NULL);
	return (1);
}

static int	init(t_state *p)
{
	int		i;

	i = -1;
	p->fork_m = NULL;
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
	return (init_mutex(p));
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
	pthread_mutex_lock(&p->dead_m);
	ft_error(p, NULL);
	return (0);
}
