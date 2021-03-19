/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:52:30 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/19 19:19:58 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	print_message(t_philo *t, int a)
{
	suseconds_t		ret;

	pthread_mutex_lock(&t->state->write_m);
	ret = takeoff_time(t->state->start);
	printf("%s%dms %sphilo %d ", KBLU, ret/1000, KWHT, t->pos);
	if (a == TYPE_EAT)
		printf("%sis eating\n", KGRN);
	if (a == TYPE_SLEEP)
		printf("%sis sleeping\n", KCYN);
	if (a == TYPE_CHOPSTICK)
		printf("%shas taken a chopstick\n", KYEL);
	if (a == TYPE_THINK)
		printf("%sis thinking\n", KMAG);
	if (a == TYPE_DIED)
		printf("%shas died\n", KRED);
	if (a == TYPE_OVER)
		printf("%smust eat count reached\n", KRED);
    pthread_mutex_unlock(&t->state->write_m);
}