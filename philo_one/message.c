/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:52:30 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/19 14:01:30 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	print_message(t_philo *t, int a)
{
	suseconds_t		ret;

	pthread_mutex_lock(&t->state->write_m);
	ret = takeoff_time(t->state->start);
	printf("%d philo %d ", ret/1000, t->pos);
	if (a == TYPE_EAT)
		printf("is eating\n");
	if (a == TYPE_SLEEP)
		printf("is sleeping\n");
	if (a == TYPE_CHOPSTICK)
		printf("has taken a chopstick\n");
	if (a == TYPE_THINK)
		printf("is thinking\n");
	if (a == TYPE_DIED)
		printf("has died\n");
    pthread_mutex_unlock(&t->state->write_m);
}