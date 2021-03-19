/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:37 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/19 13:46:46 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    pick_chopsticks(t_philo *t)
{
    pthread_mutex_lock(&t->state->fork_m[t->lfork]);
    print_message(t, TYPE_CHOPSTICK);
    pthread_mutex_lock(&t->state->fork_m[t->rfork]);
    print_message(t, TYPE_CHOPSTICK);
}

void    eat(t_philo *t)
{
	//pthread_mutex_lock(&t->mutex);
	t->is_eating = 1;
	print_message(t, TYPE_EAT);
	t->limit = sum_time(t->last_meal, t->state->tdie);
	gettimeofday(&t->last_meal, NULL);
	usleep(t->state->teat * 1000);
    printf("has aqui\n");
	t->eat_count++;
	t->is_eating = 0;
	//pthread_mutex_unlock(&t->mutex);
}

void    leave_chopsticks(t_philo *t)
{
    pthread_mutex_unlock(&t->state->fork_m[t->lfork]);
    pthread_mutex_unlock(&t->state->fork_m[t->rfork]);
    print_message(t, TYPE_SLEEP);
    usleep(t->state->tsleep * 1000);
    print_message(t, TYPE_THINK);
}
