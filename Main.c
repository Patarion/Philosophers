#include "Philo.h"

void kill_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join((data->philo_data[i].id_thread), NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->mutex_fork[i]));
	pthread_mutex_destroy(&(data->mutex_write));
	pthread_mutex_destroy(&(data->mutex_eat));
}

int main(int argc, char **argv)
{
	int				i;
	t_data			data;

	i = 2;
	if(argc < 5 || argc > 6)
		erreur_case(1, 0);
	while(is_valid(argv[i], i) == 0 && i < (argc - 1))
		i++;
	data = init_data(argc, argv);
	i = -1;
	while(++i < data.nb_philo)
	{
		if (pthread_create(&data.philo_data[i].id_thread, NULL, routine, (void*)&data.philo_data[i]) != 0)
			exit(EXIT_FAILURE);
		data.philo_data[i].t_last_meal = get_time();
	}
	check_death(&data, data.philo_data);
	kill_philo(&data, data.philo_data);
	printf("%d - %d - %d - %d - %d\n", data.time_die, data.time_eat, data.time_sleep, data.nb_eat, data.rem_eat);
}
