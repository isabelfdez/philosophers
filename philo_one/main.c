
#include "philo_one.h"

int n = 0;

int main(int argc, char **argv)
{
	t_philo *p;

	if (!check_arguments(argc, argv))
		return (-1);
	p = malloc(sizeof(t_philo));
	p->num = atoi(argv[1]);
	n = p->num;
	printf("el n vale ahora %i\n", n);
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
	pthread_mutex_t mutex;
    //mutex = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(&mutex, NULL);
    while (TRUE) 
	{
        pthread_mutex_lock(&mutex);

        // check if all COUNT_TO has been arrived at
        if (i >= COUNT_TO) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }

        ++i;

        // release lock
        pthread_mutex_unlock(&mutex);

        printf("i = %lld\n", i);
    }
    pthread_mutex_destroy(&mutex);
    //free(mutex);
}