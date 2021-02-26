/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:42:04 by isfernan          #+#    #+#             */
/*   Updated: 2021/02/26 16:25:51 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int g_n = 0;

int main(int argc, char **argv)
{
	t_philo *p;

	if (!check_arguments(argc, argv))
		return (-1);
	p = malloc(sizeof(t_philo));
	p->num = atoi(argv[1]);
	g_n = p->num;
	printf("el n vale ahora %i\n", g_n);
	p->tdie = atoi(argv[2]);
	p->teat = atoi(argv[3]);
	p->tsleep = atoi(argv[4]);
	if (argc == 6)
		p->meals = atoi(argv[5]);
	else
		p->meals = -1;
	create_threads(p);
}

int		check_arguments(int argc, char **argv)
{
	if (argc < 5)
	{
		write(1, "too few arguments\n", strlen("too few arguments\n"));
		return (0);
	}
	if (argc > 6)
	{
		write(1, "too many arguments\n", strlen("too many arguments\n"));
		return (0);
	}
	if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0 ||
		atoi(argv[4]) <= 0)
	{
		write(1, "invalid arguments\n", strlen("invalid arguments\n"));
		return (0);
	}
	if (argc == 6 && atoi(argv[5]) <= 0)
	{
		write(1, "invalid arguments\n", strlen("invalid arguments\n"));
		return (0);
	}
	return (1);
}

void	create_threads(t_philo *p)
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
}