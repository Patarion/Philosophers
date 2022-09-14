#include "Philo.h"

void kill_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->mutex_fork[i]));
	pthread_mutex_destroy(&(data->mutex_write));
	pthread_mutex_destroy(&(data->mutex_eat));
}

int main(int argc, char **argv)
{
	int				i;
	int				err;
	t_data			data;

	i = 0;
	err = 0;
	while(++i < (argc - 1) && (is_valid(argv[i], i)) == err)
		;
	if (i < (argc - 1))
		err = 1;
	data = init_data(argc, argv);
	i = -1;
	while(++i < data.nb_philo && err == 0)
	{
		if (pthread_create(&data.philo_data[i].id_thread, NULL, 
			routine, (void*)&data.philo_data[i]) != 0)
			break ;
		data.philo_data[i].t_last_meal = get_time();
	}
	if (i == data.nb_philo && err == 0)
	{
		while (check_death(&data, data.philo_data) != 1)
			;
		kill_philo(&data);
	}
}
