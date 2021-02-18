#ifndef PHILO_ONE_F
# define PHILO_ONE_F

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

typedef struct  s_philo
{
	int		num;
	int		tdie;
	int		teat;
	int		tsleep;
	int		meals;
}				t_philo;

int		check_arguments(int argc, char **argv);
void	create_threads(t_philo *p);
void	*start_tasks(void *i);



#endif