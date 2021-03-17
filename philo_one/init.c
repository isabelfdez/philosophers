/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:55:13 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/17 19:20:39 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		pthread_detach(p->philos[i].id);
		usleep(100);
	}
	return (1);
}
