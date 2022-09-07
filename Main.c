#include "Philo.h"

void kill_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(philo.philo_data[i].id_thread, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(data->mutex_fork[i]));
	pthread_mutex_destroy(&(data->mutex_write));
	pthread_mutex_destroy(&(data->mutex_eat));
}

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
	{
		if (pthread_create(&phi.philo_data[i].id_thread, NULL, routine, (void*)&phi.philo_data[i]));
			exit(EXIT_FAILURE);
		phi.t_last_meal = get_time();
	}
	check_death(phi, phi.philo);
	kill_philo(phi, phi.philo);
	printf("%d - %d - %d - %d - %d\n", phi.time_die, phi.time_eat, phi.time_sleep, phi.nb_eat, phi.rem_eat);
}
