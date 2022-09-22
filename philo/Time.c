/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:06:42 by jgagnon           #+#    #+#             */
/*   Updated: 2022/09/20 12:08:57 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

long long int	get_time(void)
{
	struct timeval	temps;
	long long int	ms_temps;

	gettimeofday(&temps, NULL);
	temps.tv_sec = temps.tv_sec * 1000;
	temps.tv_usec = temps.tv_usec / 1000;
	ms_temps = temps.tv_sec + temps.tv_usec;
	return (ms_temps);
}

void	smart_sleep(long long time, t_data *data)
{
	long long int	c_time;

	c_time = get_time();
	while (data->is_dead != true)
	{
		if ((get_time() - c_time) >= time)
			break ;
		usleep(50);
	}
}
