#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct		s_philo
{
	int				pos;
	int				is_eating;
	uint64_t		limit;
	uint64_t		last_meal;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_state	*state;
	pthread_t		id;
	//pthread_mutex_t	mutex;
	//pthread_mutex_t	eat_m;
}					t_philo;

typedef struct		s_state
{
	int				num;
	uint64_t		tdie;
	uint64_t		teat;
	uint64_t		tsleep;
	int				meals;

	uint64_t		start;

	t_philo			*philos;
	pthread_mutex_t	*fork_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	dead_m;
}					t_state;

int		check_arguments(int argc, char **argv);


/*
** utils.c
*/

int		ft_atoi(const char *str);
int     ft_error(t_state *p, char *str);
int		ft_strlen(char *str);



#endif