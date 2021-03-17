/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopsticks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:37 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/17 19:02:12 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    pick_chopsticks(t_philo *t)
{
    pthread_mutex_lock(&t->state->fork_m[t->lfork]);
    print_message(t, TYPE_CHOPSTICK);
    pthread_mutex_lock(&t->state->fork_m[t->rfork]);
    print_message(t, TYPE_CHOPSTICK);
}