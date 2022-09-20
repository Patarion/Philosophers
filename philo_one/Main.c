/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:23:37 by jgagnon           #+#    #+#             */
/*   Updated: 2022/09/20 13:23:43 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	kill_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->mutex_fork[i]));
	pthread_mutex_destroy(&(data->mutex_write));
	pthread_mutex_destroy(&(data->mutex_eat));
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && (is_valid(argv[i], i + 1) == 0))
		i++;
	if (i != argc || (argc < 5 || argc > 6))
		return (erreur_case(1));
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	int				error;
	t_data			data;

	error = check_args(argc, argv);
	if (error == 0)
		data = init_data(argc, argv);
	if (data.error == 1)
		error = erreur_case(2);
	i = -1;
	while (++i < data.nb_philo && error == 0)
	{
		if (pthread_create(&data.philo_data[i].id_thread, NULL,
				routine, (void*)&data.philo_data[i]) != 0)
			break ;
		data.philo_data[i].t_last_meal = get_time();
	}
	if (i == data.nb_philo && error == 0)
	{
		while (check_death(&data, data.philo_data) != 1)
			;
		kill_philo(&data);
		return (0);
	}
	return (1);
}
