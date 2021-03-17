/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:42:00 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/17 19:40:53 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

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

suseconds_t		takeoff_time(struct timeval a, struct timeval b)
{
	suseconds_t	aux;

	if (a.tv_sec == b.tv_sec)
		return (a.tv_usec - b.tv_usec);
	else
	{
		aux = a.tv_usec - b.tv_usec;
		return (aux + (a.tv_sec - b.tv_sec) * 1000000);
	}
}

int		main(void) 
{
	struct timeval	current_time;
	struct timeval	other;
	suseconds_t		a;

	gettimeofday(&current_time, NULL);
	printf("microsec a = %d sec a : %ld\n",
		current_time.tv_usec, current_time.tv_sec);
	other.tv_sec = current_time.tv_sec + 2;
	other.tv_usec = current_time.tv_usec + 1001; 
	a = takeoff_time(other, current_time);
	printf("ret : %d\n", a);
}

/*struct timeval current_time;
	gettimeofday(&current_time, NULL);
	suseconds_t a = current_time.tv_usec;
	time_t b = current_time.tv_sec;
	printf("milisec a = %d time a : %ld\n", a, b);
	long long h = 0;
	while (h < 1000000000)
	{
			h++;
	}
	printf("Hello world\n");
	gettimeofday(&current_time, NULL);
	suseconds_t c = current_time.tv_usec;
	time_t d = current_time.tv_sec;
	printf("milisec c = %d time c : %ld\n", c, d);
	c += (d - b) * 1000000;
	printf("time used : %d\n", c - a);

	return 0;*/