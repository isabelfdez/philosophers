/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:55:13 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/23 15:57:55 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	*monitor_count(void *phi)
{
	t_state			*p;
	int				i;

	p = (t_state *)phi;
	while (1)
	{
		i = 0;
		while (i < p->num)
		{
			if (p->philos[i].eat_count >= p->meals)
				i++;
			else
				break ;
		}
		if (i == p->num)
		{
			print_message(&p->philos[0], TYPE_OVER, 0);
			pthread_mutex_unlock(&p->dead_m);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

static void	*monitor(void *phi)
{
	t_philo			*t;
	struct timeval	ctime;

	t = (t_philo *)phi;
	while (1)
	{
		gettimeofday(&ctime, NULL);
		if (!t->is_eating && get_time(t->limit) < get_time(ctime))
		{
			print_message(t, TYPE_DIED, 0);
			pthread_mutex_unlock(&t->state->dead_m);
			return ((void *) 0);
		}
		usleep(1000);
	}
	return ((void *) 1);
}

static void	*routine(void *phi)
{
	t_philo		*t;
	pthread_t	id;

	t = (t_philo *)phi;
	t->last_meal = t->state->start;
	t->limit = sum_time(t->last_meal, t->state->tdie * 1000);
	pthread_create(&id, NULL, &monitor, phi);
	pthread_detach(id);
	while (1)
	{
		pick_chopsticks(t);
		eat(t);
		leave_chopsticks(t);
	}
	return (NULL);
}

int	init_threads(t_state *p)
{
	int			i;
	void		*phi;
	pthread_t	id;

	i = -1;
	gettimeofday(&(p->start), NULL);
	if (p->meals)
	{
		pthread_create(&id, NULL, monitor_count, (void *)p);
		pthread_detach(id);
	}	
	while (++i < p->num)
	{
		phi = (void *)(&p->philos[i]);
		if (pthread_create(&p->philos[i].id, NULL, routine, phi))
			return (0);
		pthread_detach(p->philos[i].id);
		usleep(100);
	}
	return (1);
}
