/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:51:31 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/22 20:54:44 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	*monitor_count(void *phi)
{
	t_state			*p;
	int				i;

	p = (t_state *)phi;
	i = -1;
	while (++i < p->num)
	{
		sem_wait(p->meal_count);
		//usleep(100);
	}
	print_message(&p->philos[0], TYPE_OVER, 0);
	sem_post(p->dead);	
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
			sem_post(t->state->dead);
			return ((void *) 0);
		}
		usleep(1000);
	}
	return ((void *) 1);
}

static void	*routine(t_philo *t)
{
	pthread_t	id;

	t->last_meal = t->state->start;
	t->limit = sum_time(t->last_meal, t->state->tdie * 1000);
	pthread_create(&id, NULL, &monitor, (void *)t);
	while (1)
	{
		pick_chopsticks(t);
		eat(t);
		leave_chopsticks(t);
	}
	return (NULL);
}

int	init_forks(t_state *p)
{
	int			i;
	void		*phi;
	pthread_t	id;

	i = -1;
	if (p->meals)
	{
		pthread_create(&id, NULL, monitor_count, (void *)p);
		pthread_detach(id);
	}
	usleep(200);
	gettimeofday(&(p->start), NULL);
	while (++i < p->num)
	{
		p->philos[i].pid = fork();
		if (p->philos[i].pid == 0)
		{
			routine(&p->philos[i]);
			exit(0);
		}
		usleep(100);
	}
	return (1);
}
