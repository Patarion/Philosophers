/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:33:10 by jgagnon           #+#    #+#             */
/*   Updated: 2022/09/20 14:33:12 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

t_data	init_data(int argc, char **argv)
{
	t_data	philo;

	philo.nb_philo = to_int(argv[1]);
	philo.time_die = to_int(argv[2]);
	philo.time_eat = to_int(argv[3]);
	philo.time_sleep = to_int(argv[4]);
	philo.is_dead = false;
	philo.rem_eat = true;
	philo.nb_eat = 0;
	philo.error = 0;
	philo.init_time = get_time();
	if (argc == 5)
		philo.rest_eat = INT_MAX;
	else if (argc == 6)
		philo.rest_eat = to_int(argv[5]);
	if (pthread_mutex_init(&philo.mutex_write, NULL) != 0
		|| pthread_mutex_init(&philo.mutex_eat, NULL) != 0)
		philo.error = 1;
	if (philo.error == 0)
		init_philo(&philo);
	return (philo);
}

void	init_philo(t_data *philo)
{
	int	i;

	i = philo->nb_philo;
	while (--i >= 0)
	{
		philo->philo_data[i].id_phil = i;
		philo->philo_data[i].nb_meals = 0;
		philo->philo_data[i].id_l_fork = i;
		philo->philo_data[i].id_r_fork = (i + 1) % philo->nb_philo;
		philo->philo_data[i].t_last_meal = 0;
		philo->philo_data[i].data = philo;
		if (pthread_mutex_init(&philo->mutex_fork[i], NULL) != 0)
			philo->error = 1;
	}
}
