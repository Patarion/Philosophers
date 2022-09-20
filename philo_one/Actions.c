/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:41:49 by jgagnon           #+#    #+#             */
/*   Updated: 2022/09/20 14:41:51 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	philo_eats(t_philo *philo)
{
	t_data		*data;
	short int	m1;
	short int	m2;

	data = philo->data;
	m1 = pthread_mutex_lock(&(data->mutex_fork[philo->id_l_fork]));
	m2 = pthread_mutex_lock(&(data->mutex_fork[philo->id_r_fork]));
	if (m1 == 0 && m2 == 0)
	{
		print_action(data, philo->id_phil, "has taken a fork");
		print_action(data, philo->id_phil, "has taken a fork");
		print_action(data, philo->id_phil, "is eating");
		philo->t_last_meal = get_time();
		smart_sleep(data->time_eat, data);
		philo->nb_meals++;
	}
	if (m1 == 0)
		pthread_mutex_unlock(&(data->mutex_fork[philo->id_l_fork]));
	if (m2 == 0)
		pthread_mutex_unlock(&(data->mutex_fork[philo->id_r_fork]));
}

void	check_meals(t_data *data)
{
	int	i;

	i = -1;
	while (data->philo_data[++i]. nb_meals == data->rest_eat)
		;
	if (i == data->nb_philo)
	{
		data->rem_eat = false;
		printf("Les philosophes ont fini de manger\n");
	}
}

void	*routine(void *philo_data)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_data;
	data = philo->data;
	if (philo->id_phil % 2)
		usleep(data->time_die * 100);
	while (data->is_dead != true && data->rem_eat != false)
	{
		philo_eats(philo);
		if (data->time_sleep > 0)
			print_action(data, philo->id_phil, "is sleeping");
		smart_sleep(data->time_sleep, data);
		print_action(data, philo->id_phil, "is thinking");
	}
	return (0);
}

void	print_action(t_data *data, int id, char *string)
{
	long long int	time;

	time = get_time() - data->init_time;
	pthread_mutex_lock(&data->mutex_write);
	if (data->is_dead != true)
	{
		printf("%lli ", time);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	if (data->is_dead == true)
	{
		printf("%lli ", time);
		printf("%i ", id + 1);
		printf("died\n");
	}
	pthread_mutex_unlock(&data->mutex_write);
}

int	check_death(t_data *data, t_philo *philo)
{
	int	i;

	while (data->rem_eat == true)
	{
		i = -1;
		while (++i < data->nb_philo && (data->is_dead != true))
		{
			if ((get_time() - philo[i].t_last_meal) > data->time_die)
			{
				data->is_dead = true;
				print_action(data, i, "died");
			}
			usleep(100);
		}
		check_meals(data);
		if (data->is_dead == true)
			break ;
		i = -1;
	}
	return (1);
}
