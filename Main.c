#include "Philo.h"


void *PrintHello(void *data)
{
	t_philo *phil;

	phil = (t_philo*)data;
	printf("Hello from new thread got %d\n", phil->nb_philo);
	access_fork(phil);
	return (0);
}
/*
void *routine(void *philo)
{

}*/
/*
int main(int argc, char **argv)
{
	pthread_t	thread_id[5];
	int			*t;
	int			i;

	i = -1;
	t = malloc(sizeof(int));
	*t = 5;
	while (++i < 5)
	{
		pthread_create(&thread_id[i], NULL, PrintHello, (void*)t);
	}
	if (!thread_id[i])
	{
		printf("Le thread n'a pas été créé\n");
		exit(1);
	}
	i = -1;
	while (++i < 5)
	{
		printf("Le thread %d est fermé\n", i);
		pthread_join(thread_id[i], NULL);
	}
	free(t);
}*/

int main(int argc, char **argv)
{
	int				i;
	t_philo			phi;

	i = 2;
	if(argc < 5 || argc > 6)
		erreur_case(1, 0);
	while(is_valid(argv[i], i) == 0 && i < (argc - 1))
		i++;
	phi = init_data(argc, argv);
	i = -1;
	while(++i < phi.nb_philo)
		pthread_create(&phi.philo_data[i].id_thread, NULL, PrintHello, (void*)&phi.philo_data[i]);
	if (phi.is_dead == true)
		while(--i >= 0)
			pthread_join(phi.philo_data[i].id_thread, NULL);
	printf("%d - %d - %d - %d - %d\n", phi.time_die, phi.time_eat, phi.time_sleep, phi.nb_eat, phi.rem_eat);
}
