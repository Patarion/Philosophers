#include "Philo.h"

int only_digit(char *arg)
{
    int i;

    i = 0;
    if (arg[i] == '\0')
        return (1);
    else if (arg[i] == '-')
        return(1);
    while (arg[i] >= '0' && arg[i] <= '9' && arg[i] != '\0')
        i++;
    if (arg[i] == '\0')
        return (0);
    return (1);
}

int is_int(char *arg, int argc)
{
    int                 i;
    long long int       nbr;

    i = 0;
    nbr = 0;
    while(arg[i] != '\0')
    {
        nbr = (nbr * 10) + (arg[i] - '0');
        i++;
    }
    if (nbr > INT_MAX || nbr < INT_MIN)
        return(1);
    if (nbr == 0)
        return(1);
    if (((nbr > MAX_PHILO || nbr < 1) && argc == 2))
        return(1);
    return (0);
}

int to_int(char *arg)
{
    int             i;
    unsigned int    nbr;

    if (!arg)
        return(1);
    i = 0;
    nbr = 0;
    while(arg[i] != '\0')
    {
        nbr = (nbr * 10) + (arg[i] - '0');
        i++;
    }
    return(nbr);
}

int is_valid(char *arg, int argc)
{
    if(only_digit(arg) != 0)
        return(1);
    if(is_int(arg, argc) != 0)
        return(1);
    return(0);
}

t_data init_data(int argc, char **argv)
{
    t_data  philo;

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
    if (pthread_mutex_init(&philo.mutex_write, NULL) != 0 ||
        pthread_mutex_init(&philo.mutex_eat, NULL) != 0)
        philo.error = 1;
    if (philo.error == 0)
        init_philo(&philo);
    return (philo);
}

void init_philo(t_data *philo)
{
    int i;

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
