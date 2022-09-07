void philo_eats(t_philo philo)
{
    t_data *data;

    data = philo->data;
    pthread_mutex_lock(&(data->mutex_fork[philo->id_l_fork]));
    print_action(data, philo->id, "a pris une fourchette");
    pthread_mutex_lock(&(data->mutex_fork[philo->id_r_fork]));
    print_action(data, philo->id, "a pris une fourchette");
    pthread_mutex_lock(&(data->mutex_eat));
    smart_sleep(data->time_eat, data);
    philo->nb_eat++;
    pthread_mutex_unlock(&(data->mutex_eat));
    pthread_mutex_unlock(&(data->mutex_fork[philo->id_l_fork]));
    pthread_mutex_unlock(&(data->mutex_fork[philo->id_r_fork]));
}

int routine(void *philo_data)
{
    t_philo *philo;
    t_data  *data;

    philo = (t_philo *)philo_data;
    data = philo->data;
    if (philo->id_phil %2)
        usleep(15000);
    while (philo->is_dead != true)
    {
        philo_eats(philo);
        if (data->rem_eat == false)
            break ;
        print_action(data, philo->id, "is sleeping");
        smart_sleep(data->time_sleep, data);
        print_action(data, philo->id, "is thinking");
    }
}

void print_action(t_data *data, int id, char *string)
{
    pthread_mutex_lock(&data->mutex_write);
    if (data->is_dead != true)
    {
        printf("%lli ", get_time() - data->init_time);
        printf("%i ", id + 1);
        printf("%s\n", string);
    }
    pthread_mutex_unlock(&data->mutex_write);
}

void check_death(t_data *data, t_philo *philo)
{
    int i;

    while (data->rem_eat == true)
    {
        i = -1;
        while (++i < data->nb_philo && (data->is_dead != true))
        {
            phtread_mutex_lock(&(data->mutex_eat));
            if (philo[i].t_last_meal - get_time(()) > data->time_die)
            {
                print_action(data, i, "est mort");
                data->is_dead == true;
            }
            pthread_mutex_unlock(&(data->mutex_eat));
            usleep(100);
        }
        if (data->is_dead == true)
            break ;
        i = -1;
        while (data->rest_eat != INT_MAX && i < data->nb_philo && p[i].nb_eat >= data->rest_eat)
            i++;
        if (i == data->nb_philo)
            data->rem_eat = false;
    }
}