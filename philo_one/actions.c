/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:37 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/23 16:10:48 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	pick_chopsticks(t_philo *t)
{
	pthread_mutex_lock(&t->state->fork_m[t->lfork]);
	print_message(t, TYPE_CHOPSTICK, 1);
	pthread_mutex_lock(&t->state->fork_m[t->rfork]);
	print_message(t, TYPE_CHOPSTICK, 1);
}

void	eat(t_philo *t)
{
	t->is_eating = 1;
	print_message(t, TYPE_EAT, 1);
	gettimeofday(&t->last_meal, NULL);
	t->limit = sum_time(t->last_meal, t->state->tdie * 1000);
	t->eat_count++;
	usleep(t->state->teat * 1000);
	t->is_eating = 0;
}

void	leave_chopsticks(t_philo *t)
{
	pthread_mutex_unlock(&t->state->fork_m[t->lfork]);
	pthread_mutex_unlock(&t->state->fork_m[t->rfork]);
	print_message(t, TYPE_SLEEP, 1);
	usleep(t->state->tsleep * 1000);
	print_message(t, TYPE_THINK, 1);
}
