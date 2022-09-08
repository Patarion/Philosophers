#include "Philo.h"

int only_digit(char *arg, int arg_num)
{
    int i;

    i = 0;
    if (arg[i] == '\0')
        return (1);
    else if (arg[i] == '-')
        erreur_case(4, arg_num);
    while (arg[i] >= '0' && arg[i] <= '9' && arg[i] != '\0')
        i++;
    if (arg[i] == '\0')
        return (0);
    return (1);
}

int is_int(char *arg, int arg_num)
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
        erreur_case(3, arg_num);
    if (nbr == 0)
        erreur_case(4, arg_num);
    if ((nbr > MAX_PHILO || nbr < 2) && arg_num == 1)
        erreur_case(6, 0);
    return (0);
}

int to_int(char *arg, int arg_num)
{
    int             i;
    unsigned int    nbr;

    if (arg_num == 1 && arg != NULL)
        is_valid(arg, 1);
    else if (arg == NULL)
        erreur_case(1, 0);
    i = 0;
    nbr = 0;
    while(arg[i] != '\0')
    {
        nbr = (nbr * 10) + (arg[i] - '0');
        i++;
    }
    return (nbr);
}

int is_valid(char *arg, int arg_num)
{
    if(only_digit(arg, arg_num) != 0)
        erreur_case(2, arg_num);
    if(is_int(arg, arg_num) != 0)
        erreur_case(3, arg_num);
    return (0);
}

t_data init_data(int argc, char **argv)
{
    t_data  philo;

    philo.nb_philo = to_int(argv[1], 0);
    philo.time_die = to_int(argv[2], 2);
    philo.time_eat = to_int(argv[3], 3);
    philo.time_sleep = to_int(argv[4], 4);
    philo.is_dead = false;
    philo.rem_eat = true;
    philo.nb_eat = 0;
    philo.init_time = get_time();
    if (argc == 5)
        philo.rest_eat = INT_MAX;
    else if (argc == 6)
        philo.rest_eat = to_int(argv[5], 5);
    if (pthread_mutex_init(&philo.mutex_write, NULL) != 0 || 
        pthread_mutex_init(&philo.mutex_eat, NULL) != 0)
        erreur_case(5, 0);
    init_philo(&philo);
    return (philo);
}

void init_philo(t_data *philo)
{
    int i;

    i = philo->nb_philo;
    while (--i >= 0)
    {
        printf("%p\n", philo);
        philo->philo_data[i].id_phil = i;
        philo->philo_data[i].nb_meals = 0;
        philo->philo_data[i].id_l_fork = i;
        philo->philo_data[i].id_r_fork = (i + 1) % philo->nb_philo;
        philo->philo_data[i].t_last_meal = 0;
        philo->philo_data[i].data = philo;
        if (pthread_mutex_init(&philo->mutex_fork[i], NULL) != 0)
            erreur_case(5, 0);
    }
}
