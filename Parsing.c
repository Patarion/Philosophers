/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:32:59 by jgagnon           #+#    #+#             */
/*   Updated: 2022/09/20 14:33:01 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int	only_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '\0')
		return (1);
	else if (arg[i] == '-')
		return (1);
	while (arg[i] >= '0' && arg[i] <= '9' && arg[i] != '\0')
		i++;
	if (arg[i] == '\0')
		return (0);
	return (1);
}

int	is_int(char *arg, int argc)
{
	int				i;
	short int		signe;
	long long int	nbr;

	i = 0;
	nbr = 0;
	signe = 1;
	if (arg[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (arg[i] != '\0')
	{
		nbr = (nbr * 10) + (arg[i] - '0');
		i++;
	}
	nbr = nbr * signe;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	if (nbr == 0)
		return (1);
	if (((nbr > MAX_PHILO || nbr < 1) && argc == 2))
		return (1);
	return (0);
}

int	to_int(char *arg)
{
	int				i;
	unsigned int	nbr;

	if (!arg)
		return (1);
	i = 0;
	nbr = 0;
	while (arg[i] != '\0')
	{
		nbr = (nbr * 10) + (arg[i] - '0');
		i++;
	}
	return (nbr);
}

int	is_valid(char *arg, int argc)
{
	if (only_digit(arg) != 0)
		return (1);
	if (is_int(arg, argc) != 0)
		return (1);
	return (0);
}
