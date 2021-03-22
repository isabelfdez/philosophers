/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:26:33 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/22 18:36:52 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

struct timeval	sum_time(struct timeval a, suseconds_t b)
{
	struct timeval	c;

	c.tv_usec = b + a.tv_usec;
	if (c.tv_usec < 1000000)
		c.tv_sec = a.tv_sec;
	else
	{
		c.tv_sec = a.tv_sec + 1;
		c.tv_usec = c.tv_usec - 1000000;
	}
	return (c);
}

suseconds_t	takeoff_time(struct timeval b)
{
	struct timeval	a;

	gettimeofday(&a, NULL);
	return (a.tv_usec - b.tv_usec + (a.tv_sec - b.tv_sec) * 1000000);
}

uint64_t	get_time(struct timeval tv)
{
	return ((tv.tv_sec * (uint64_t) 1000) + (tv.tv_usec / 1000));
}
