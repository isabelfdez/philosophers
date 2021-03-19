/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:55:13 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/19 14:05:14 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*routine(void *phi)
{
	t_philo *t;

	t = (t_philo *)phi;
	t->last_meal = t->state->start;
	t->limit = sum_time(t->last_meal, t->state->tdie);
	while (1)
	{
		pick_chopsticks(t);
		eat(t);
		leave_chopsticks(t);
	}
	return (NULL);
}

int		init(t_state *p)
{
	int		i;

	i = -1;
	p->fork_m = NULL;
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

int		init_mutex(t_state *p)
{
	int		i;

	i = -1;
	
	pthread_mutex_init(&p->write_m, NULL);
	pthread_mutex_init(&p->dead_m, NULL);
	//pthread_mutex_lock(&p->dead_m);
	if (!(p->fork_m = malloc(sizeof(pthread_mutex_t) * p->num)))
		return (0);
	while (++i < p->num)
		pthread_mutex_init(&p->fork_m[i], NULL);
	return (1);
}

int		init_threads(t_state *p)
{
	int		i;
	void	*phi;

	i = -1;
	gettimeofday(&(p->start), NULL);
	while (++i < p->num)
	{
		phi = (void *)(&p->philos[i]);
		if (pthread_create(&p->philos[i].id, NULL, routine, phi))
			return (0);
		//usleep(100);
		pthread_detach(p->philos[i].id);
	}
	return (1);
}
