/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:42:04 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/15 20:51:18 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		check_arguments(int argc, char **argv)
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
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 ||
		ft_atoi(argv[4]) <= 0)
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

int		init_mutex(t_state *p)
{
	int		i;

	i = -1;
	
	//pthread_mutex_init(&p->write_m, NULL);
	pthread_mutex_init(&p->dead_m, NULL);
	//pthread_mutex_lock(&p->dead_m);
	if (!(p->fork_m = malloc(sizeof(pthread_mutex_t) * p->num)))
		return (0);
	while (++i < p->num)
		pthread_mutex_init(&p->fork_m[i], NULL);
	return (1);
}

int		init(t_state *p)
{
	int		i;

	i = -1;
	//p->fork_m = NULL;
	//p->philo = NULL;
	if (!(p->philos = malloc(sizeof(t_philo) * p->num)))
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

void	*routine(void *phi)
{
	t_philo *t;

	t = (t_philo *)phi;
	while (1)
	{
		eat(t_philo);
		
	}
}

int		init_threads(t_state *p)
{
	int		i;
	void	*phi;

	i = -1;
	while (++i < p->num)
	{
		phi = (void *)(&p->philos[i]);
		if (pthread_create(&p->philos[i].id, NULL, routine, phi))
			return (0);
		pthread_detach(p->philos[i]);
		usleep(100);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_state *p;

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
		p->meals = -1;
	if (!init(p))
		return (ft_error(p, "Memory allocation error\n"));
	if (!init_threads(p))
		return (ft_error(p, NULL)); /* Aquí hay que cambiarlo */
}

/*void	create_threads(t_philo *p)
{
	pthread_t	*threads;
	long		i;
	int			j;

	i = 0;
	j = 0;
	threads = malloc(sizeof(pthread_t) * p->num);
	while (i < p->num)
	{
		 pthread_create(&threads[i], NULL, start_tasks, (void *)i);
		 i++;
	}
	while (j < p->num)
	{
        pthread_join(threads[j], NULL);
		j++;
	}
}

void	*start_tasks(void *i)
{
	int		j;
	int		*i2;

	j = 0;
	i2 = i;
	pthread_mutex_t *mutex;
	mutex = malloc(sizeof(pthread_mutex_t) * (g_n));
	printf("hasta aquí\n");
	while (j < g_n)
	{
		pthread_mutex_init(&(mutex[j]), NULL);
		j++;
	}
	while (1)
	{
		pthread_mutex_lock(&mutex[*i2]);
		if (*i2 == g_n)
			pthread_mutex_lock(&mutex[0]);
		else
			pthread_mutex_lock(&mutex[*i2 + 1]);
		
		printf("philo %i has taken a fork\n", *i2);
		pthread_mutex_unlock(&mutex[*i2]);
	}
	//pthread_mutex_destroy(&mutex);
	free(mutex);
}*/